//
// Created by Sophia on 30.05.2020.
//

#include <iomanip>
#include "Number.h"
Number::Number (string str)
{
        if (str.length() == 0)
        {
            this->IsNegative = false;
        }
        else
        {
            if (str[0] == '-')
            {
                str = str.substr(1);
                this->IsNegative = true;
            }
            else
            {
                this->IsNegative = false;
            }
            for (long long i = str.length(); i > 0; i -= 9) {
                if (i < 9)
                    this->digits.push_back( atoi(str.substr(0, i).c_str()) );
                else
                    this->digits.push_back( atoi(str.substr(i - 9, 9).c_str()));
            }
            this->RemoveLeadingZeros();
        }

}

void Number::RemoveLeadingZeros()
{
    while (this->digits.size() > 1 && this->digits.back() == 0)
    {
        this->digits.pop_back();
    }

    if (this->digits.size() == 1 && this->digits[0] == 0)
        this->IsNegative = false;
}

std::ostream& operator <<(std::ostream& os, const Number& number)
{
    if ( number.digits.empty() )
        os << 0;
    else
    {
        if ( number.IsNegative)
            os << '-';
        os << number.digits.back();
        char old_fill = os.fill('0');
        for ( long long i = static_cast < long long > ( number.digits.size() ) - 2; i >= 0; --i)
        {
            os << std::setw(9) << number.digits[i];
        }

        os.fill(old_fill);
    }

    return os;
}

bool operator ==(const Number& number1, const Number& number2)
{
    if (number1.IsNegative != number2.IsNegative)
        return false;
    if ( number1.digits.empty() )
    {
        if (number1.digits.empty()
            || (number2.digits.size() == 1
                && number2.digits[0] == 0)
                )
            return true;
        else
            return false;
    }

    if ( number2.digits.empty() )
    {
        if ( number1.digits.size() == 1
            && number1.digits[0] == 0
            )
            return true;
        else
            return false;
    }

    if (number1.digits.size() != number2.digits.size())
        return false;
    for (size_t i = 0; i < number1.digits.size(); ++i)
        if (number1.digits[i] != number2.digits[i])
            return false;
    return true;
}

bool operator <(const Number& number1, const Number& number2)
{
    if ( number1 == number2 )
        return false;
    if ( number1.IsNegative )
    {
        if ( number2.IsNegative )
            return ((-number2) < (-number1));
        else return true;
    }
    else if (number2.IsNegative)
        return false;
    else
    {
        if (number1.digits.size() != number2.digits.size())
        {
            return number1.digits.size() < number2.digits.size();
        }
        else
        {
            for (long long i = number1.digits.size() - 1; i >= 0; --i)
            {
                if (number1.digits[i] != number2.digits[i])
                    return number1.digits[i] < number2.digits[i];
            }

            return false;
        }
    }
}

const Number Number::operator +() const
{
    return Number(*this);
}

const Number Number::operator -() const
{
    Number copy(*this);
    copy.IsNegative = !copy.IsNegative;
    return copy;
}

Number::operator std::string() const
{
    std::stringstream ss;
    ss << *this;
    return ss.str();
}

bool operator != (const Number& left, const Number& right)
{
    return !(left == right);
}

bool operator <= (const Number& left, const Number& right)
{
    return (left < right || left == right);
}

bool operator > (const Number& left, const Number& right)
{
    return !(left <= right);
}

bool operator >=(const Number& left, const Number& right)
{
    return !(left < right);
}
const Number operator +(Number left, const Number& right)
{
    if (left.IsNegative)
    {
        if (right.IsNegative)
            return -(-left + (-right));
        else return right - (-left);
    }
    else if (right.IsNegative)
        return left - (-right);
    int carry = 0;
    for (size_t i = 0; i < std::max(left.digits.size(), right.digits.size()) || carry != 0; ++i)
    {
        if (i == left.digits.size())
            left.digits.push_back(0);
        left.digits[i] += carry + (i < right.digits.size() ? right.digits[i] : 0);
        carry = left.digits[i] >= Number::BASE;
        if (carry != 0)
            left.digits[i] -= Number::BASE;
    }

    return left;
}

const Number operator -(Number left, const Number& right)
{
    if (right.IsNegative)
        return left + (-right);
    else if (left.IsNegative)
        return -(-left + right);
    else if (left < right)
        return -(right - left);
    int carry = 0;
    for (size_t i = 0; i < right.digits.size() || carry != 0; ++i)
    {
        left.digits[i] -= carry + (i < right.digits.size() ? right.digits[i] : 0);
        carry = left.digits[i] < 0;
        if (carry != 0) left.digits[i] += Number::BASE;
    }

    left.RemoveLeadingZeros();
    return left;
}

Number& Number::operator +=(const Number& value)
{
    return *this = (*this + value);
}

Number& Number::operator *=(const Number& value)
{
    return *this = (*this * value);
}

Number& Number::operator -=(const Number& value)
{
    return *this = (*this - value);
}

const Number operator *(const Number& left, const Number& right)
{
    Number result("");
    result.digits.resize(left.digits.size() + right.digits.size());
    for (size_t i = 0; i < left.digits.size(); ++i)
    {
        int carry = 0;
        for (size_t j = 0; j < right.digits.size() || carry != 0; ++j)
        {
            long long cur = result.digits[i + j] +
                            left.digits[i] * 1LL * (j < right.digits.size() ? right.digits[j] : 0) + carry;
            result.digits[i + j] = static_cast<int>(cur % Number::BASE);
            carry = static_cast<int>(cur / Number::BASE);
        }
    }
    result.IsNegative = left.IsNegative != right.IsNegative;
    result.RemoveLeadingZeros();
    return result;
}

const Number operator *(const Number& left, const int& right)
{

    string RightNumber = to_string(right);
   Number result = left*Number(RightNumber);
    return result;
}

void Number::_shift_right()
{
    if (this->digits.size() == 0)
    {
        this->digits.push_back(0);
        return;
    }
    this->digits.push_back(this->digits[this->digits.size() - 1]);
    for (size_t i = this->digits.size() - 2; i > 0; --i) this->digits[i] = this->digits[i - 1];
    this->digits[0] = 0;
}

const Number operator /(const Number& left, const Number& right)
{
    Number result(""), current("");
        Number b = right;
            b.IsNegative = false;

            result.digits.resize(left.digits.size());
            for (long long i = static_cast<long long>(left.digits.size()) - 1; i >= 0; --i)
            {
                current._shift_right();
                current.digits[0] = left.digits[i];
                current.RemoveLeadingZeros();
                int x = 0, l = 0, r = Number::BASE;
                while (l <= r)
                {

                    int m = (l + r) / 2;
                    Number t("");
                    t = b * m;
                    if (t <= current)
                    {
                        x = m;
                        l = m + 1;
                    }
                    else r = m - 1;
                }
                result.digits[i] = x;
                current = current - b * x;
            }

            result.IsNegative = left.IsNegative != right.IsNegative;
            result.RemoveLeadingZeros();

    return result;
}

Number& Number::operator /= (const Number& value)
{
    return *this = (*this / value);
}

const Number operator %(const Number& left, const Number& right)
{
    Number result = left - (left / right) * right;
    if (result.IsNegative) result += right;
    return result;
}
bool Number::odd() const
{
    if (this->digits.size() == 0)
        return false;
    return this->digits[0] & 1;
}

bool Number::even() const
{
    return !this->odd();
}

const Number Number::pow(Number n) const
{
    Number a(*this), result("1");
    while (n != Number("0"))
    {
        if (n.odd())
        {
            result *= a;
        }
        a *= a;
        n /= Number("2");
    }

    return result;
}

const Number Number::operator++()
{
    return (*this += Number("1"));
}

const Number Number::operator ++(int)
{
    *this += Number("1");
    return *this - Number("1");
}

const Number Number::operator --()
{
    return *this -= Number("1");
}

const Number Number::operator --(int)
{
    *this -= Number("1");
    return *this + Number("1");
}
void Number::Do()
{
   Number resalt("");
   resalt = Number("1905768493000000000000000000000000000000000000000")/Number("1235580495860935860989086039809357680399483093049");
    cout<<endl<<"1905768493000000000000000000000000000000000000000 /\n 1235580495860935860989086039809357680399483093049\n ="<<resalt;
    Number resalt2("");
    resalt2 = Number("6")*Number("2");
    cout<<endl<<"6*2="<<resalt2;
    Number resalt3("");
    resalt3 = Number("6")%Number("2");
    cout<<endl<<"6%2="<<resalt3;
    Number bi("2"), bi2 ("100");
    cout <<endl<<"pow(2, 100) = "<< bi.pow(Number("100")) ;
    cout<<endl<<"2+100 = "<<bi+bi2;
    cout<<endl<<"2-100 ="<<bi-bi2;
    cout<<endl<<"2<100 = ";
    if(Number("2")<Number("100"))
        cout<<"True";
    else
        cout<<"False";

    cout<<endl<<"100<=100 = ";
    if(Number("100")<=Number("100"))
        cout<<"True";
    else
        cout<<"False";

    cout<<endl<<"2>100 = ";
    if(Number("2")>Number("100"))
        cout<<"True";
    else
        cout<<"False";

    cout<<endl<<"2!=100 = ";
    if(Number("2")!=Number("100"))
        cout<<"True";
    else
        cout<<"False";

    cout<<endl<<"6/4 = "<<Number("6")/Number("4");

    cout<<endl<<"1000000000000000000000000000000000000000000000000000000000 + \n100000000000000000000000000000000000000000000000"<<endl<<"= "<<Number("1000000000000000000000000000000000000000000000000000000000")+Number("100000000000000000000000000000000000000000000000");
}
