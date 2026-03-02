cmake_minimum_required(VERSION 3.22)
# Enable CMake support for ASM and C languages
enable_language(C ASM)
# STM32CubeMX generated symbols (macros)
set(MX_Defines_Syms 
	USE_HAL_DRIVER
    LS2K0300
    $<$<CONFIG:Debug>:DEBUG>
)

set(LS2K_HAL_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../Drivers/LS2K03xx_HAL_Driver)
set(LSSIS_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../Drivers/LSSIS)

# STM32CubeMX generated include paths
set(MX_Include_Dirs
    ${CMAKE_CURRENT_SOURCE_DIR}/../Core/Inc
    ${LS2K_HAL_ROOT}/Inc
    ${LSSIS_ROOT}/Device/Loongson/LS2K03xx/Include
    ${LSSIS_ROOT}/Include
)

# STM32CubeMX generated application sources
set(MX_Application_Src
    ${CMAKE_CURRENT_SOURCE_DIR}/../Core/Src/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../Core/Src/ls2k03xx_it.c
    ${LSSIS_ROOT}/Device/Loongson/LS2K03xx/Source/Templates/gcc/startup_ls2k0300.S
)

# LS2K HAL Drivers
set(LS2K_Drivers_Src
    ${LSSIS_ROOT}/Device/Loongson/LS2K03xx/Source/Templates/system_ls2k03xx.c
    ${LS2K_HAL_ROOT}/Src/ls2k03xx_hal.c
    ${LS2K_HAL_ROOT}/Src/ls2k03xx_hal_gpio.c
    ${LS2K_HAL_ROOT}/Src/ls2k03xx_hal_tim.c
    ${LS2K_HAL_ROOT}/Src/ls2k03xx_hal_tim_ex.c
)

# Drivers Midllewares



# Link directories setup
set(MX_LINK_DIRS

)
# Project static libraries
set(MX_LINK_LIBS 
    LS2K_Drivers
    ${TOOLCHAIN_LINK_LIBRARIES}
    
)
# Interface library for includes and symbols
add_library(stm32cubemx INTERFACE)
target_include_directories(stm32cubemx INTERFACE ${MX_Include_Dirs})
target_compile_definitions(stm32cubemx INTERFACE ${MX_Defines_Syms})

# Create LS2K_Drivers static library
add_library(LS2K_Drivers OBJECT)
target_sources(LS2K_Drivers PRIVATE ${LS2K_Drivers_Src})
target_link_libraries(LS2K_Drivers PUBLIC stm32cubemx)


# Add STM32CubeMX generated application sources to the project
target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${MX_Application_Src})

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE ${MX_LINK_DIRS})

# Add libraries to the project
target_link_libraries(${CMAKE_PROJECT_NAME} ${MX_LINK_LIBS})

# Add the map file to the list of files to be removed with 'clean' target
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES ADDITIONAL_CLEAN_FILES ${CMAKE_PROJECT_NAME}.map)
