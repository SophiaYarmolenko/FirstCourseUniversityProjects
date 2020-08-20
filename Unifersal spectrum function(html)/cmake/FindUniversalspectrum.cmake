set(FIND_UNIVERSALSPECTRUM_PATHS
        C:/Users/Sophia/Desktop/universalspectrum)
find_path(UNIVERSALSPECTRUM_INCLUDE_DIR universalspectrum.hpp
        PATH_SUFFIXES includes
        PATHS ${FIND_UNIVERSALSPECTRUM_PATHS})
find_library(UNIVERSALSPECTRUM_LIBRARY
        NAMES universalspectrum
        PATH_SUFFIXES libraries
        PATHS ${FIND_UNIVERSALSPECTRUM_PATHS})