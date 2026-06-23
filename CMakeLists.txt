cmake_minimum_required(VERSION 3.13)

project(ToSTrigger)
list(APPEND CMAKE_PREFIX_PATH "$ENV{GEODE_SDK}")
# Bulut derleyicisinin Geode yollarını otomatik tanıması için eklenen köprü
if(DEFINED ENV{GEODE_SDK})
    list(APPEND CMAKE_PREFIX_PATH "$ENV{GEODE_SDK}")
endif()

find_package(Geode REQUIRED)

add_geode_mod(
    ID yusoft.tostrigger
    VERSION 1.0.0
    NAME "Terms of Service Trigger"
    DEVELOPER "YuSoft"
    DESCRIPTION "Adds a mandatory Terms of Service trigger."
)

add_subdirectory(src)
