cmake_minimum_required(VERSION 3.13)

# Eski CPM çakışmalarını tamamen önlemek için bypass politikası
if(POLICY CMP0048)
  cmake_policy(SET CMP0048 NEW)
endif()

project(ToSTrigger)

find_package(Geode REQUIRED)

add_geode_mod(
    ID yusoft.tostrigger
    VERSION 1.0.0
    NAME "Terms of Service Trigger"
    DEVELOPER "YuSoft"
    DESCRIPTION "Adds a mandatory Terms of Service trigger."
)

add_subdirectory(src)
