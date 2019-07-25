#ifndef ___PLATFORM_SPECIFIC___
#define ___PLATFORM_SPECIFIC___

//
// Operating system
// FO_WINDOWS
// FO_LINUX
// FO_MACOSX
//
// CPU
// FO_X86
// FO_X64 - todo
//
// Compiler
// FO_GCC
// FO_MSVC
//

//
// GCC options
// Compiler
//  Directories
//   ../Source/StlPort
//   ../Source
//  Options
//   -std=gnu++0x
//   -W
//   -Wno-invalid-offsetof
//   -Wno-unused-result
// Linker
//  Directories
//   ../Lib/Linux or ../Lib/MacOSX
//

// Detect operating system
#if defined ( _WIN32 ) || defined ( _WIN64 )
# define FO_WINDOWS
#elif defined ( __linux__ )
# define FO_LINUX
#elif defined ( __APPLE__ )
# define FO_MACOSX
#else
# error "Unknown operating system."
#endif

// Detect compiler
#if defined ( __GNUC__ )
# define FO_GCC
#elif defined ( _MSC_VER ) && !defined ( __MWERKS__ )
# define FO_MSVC
#else
# error "Unknown compiler."
#endif

// Detect CPU
#if ( defined ( FO_MSVC ) && defined ( _M_IX86 ) ) || ( defined ( FO_GCC ) && !defined ( __LP64__ ) )
# define FO_X86
#elif ( defined ( FO_MSVC ) && defined ( _M_X64 ) ) || ( defined ( FO_GCC ) && defined ( __LP64__ ) )
# define FO_X64
# error "X64 CPU not supported for now."
#else
# error "Unknown CPU."
#endif

// TLS
#if defined ( FO_MSVC )
# define THREAD    __declspec( thread )
#elif defined ( FO_GCC )
# define THREAD    __thread
#endif

// Function name
#if defined ( FO_MSVC )
# define _FUNC_    __FUNCTION__
#elif defined ( FO_GCC )
# define _FUNC_    __PRETTY_FUNCTION__
#endif

// Disable deprecated notification in GCC
#if defined ( FO_GCC )
# undef __DEPRECATED
#endif

// Libevent workarounds
// Was bugged for Windows, need retest
#ifndef FO_WINDOWS
# define USE_LIBEVENT
// Linux don't want call write timeouts, need to know why and fix
# define LIBEVENT_TIMEOUTS_WORKAROUND
#endif

#endif // ___PLATFORM_SPECIFIC___
