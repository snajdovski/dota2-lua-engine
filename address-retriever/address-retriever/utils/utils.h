#pragma once

#include <string>
#include <windows.h>
#include <stdint.h>

namespace utils {
  const unsigned char* FindPattern(const void* address, size_t size, const unsigned char* signature, const char* mask);
  const unsigned char* FindPattern(const char* module_name, const unsigned char* signature, const char* mask);
  const uint32_t* FindPattern(const char* module_name, const unsigned char* signature, const char* mask, int offset);
  uint32_t GetAbsoluteAddress(uint32_t relative_address);
  size_t GetModuleSize(const char* module_name);
  std::string GetModulePath(HMODULE module);
  HMODULE GetCurrentModule();
  HMODULE GetModuleHandleSafe(const char* module_name );
  void Log(const char* format, ...);
  const std::wstring ConvertToWide(const char *text);
  const std::string ConvertToANSI(const wchar_t *text);

  inline void**& GetVtable( void* inst, size_t offset = 0 )
  {
    return *reinterpret_cast<void***>( (size_t)inst + offset );
  }
  inline const void** GetVtable( const void* inst, size_t offset = 0 )
  {
    return *reinterpret_cast<const void***>( (size_t)inst + offset );
  }
  template< typename Fn >
  inline Fn GetVtableFunction( const void* inst, size_t index, size_t offset = 0 )
  {
    return reinterpret_cast<Fn>( GetVtable( inst, offset )[ index ] );
  }
  int ConvertANSIToUnicode(const char *ansi, wchar_t *unicode, int unicodeBufferSizeInBytes);
  int ConvertUnicodeToANSI(const wchar_t *unicode, char *ansi, int ansiBufferSize);
}