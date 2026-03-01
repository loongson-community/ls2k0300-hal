#ifndef __CORE_LA264_H_GENERIC
#define __CORE_LA264_H_GENERIC

// #include <stdint.h>

#ifdef __cplusplus
 extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CORE_LA264_H_GENERIC */

#ifndef __LSSIS_GENERIC

#ifndef __CORE_LA264_H_DEPENDANT
#define __CORE_LA264_H_DEPENDANT

#ifdef __cplusplus
 extern "C" {
#endif

/* IO definitions (access restrictions to peripheral registers) */
/**
    \defgroup LSSIS_glob_defs LSSIS Global Defines

    <strong>IO Type Qualifiers</strong> are used
    \li to specify the access to peripheral variables.
    \li for automatic generation of peripheral register debug information.
*/
#ifdef __cplusplus
  #define   __I     volatile             /*!< Defines 'read only' permissions */
#else
  #define   __I     volatile const       /*!< Defines 'read only' permissions */
#endif
#define     __O     volatile             /*!< Defines 'write only' permissions */
#define     __IO    volatile             /*!< Defines 'read / write' permissions */

/* following defines should be used for structure members */
#define     __IM     volatile const      /*! Defines 'read only' structure member permissions */
#define     __OM     volatile            /*! Defines 'write only' structure member permissions */
#define     __IOM    volatile            /*! Defines 'read / write' structure member permissions */

#ifdef __cplusplus
}
#endif

#endif /* __CORE_LA264_H_DEPENDANT */

#endif /* __LSSIS_GENERIC */
