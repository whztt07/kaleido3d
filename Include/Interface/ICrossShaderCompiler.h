#pragma once

#include "IModule.h"
#include "RHIEnums.h"
#include "ShaderCommon.h"

K3D_COMMON_NS
{
  /**
   * ShaderCompiler interface
   */
  struct IShCompiler
  {
    typedef ::k3d::SharedPtr<IShCompiler> Ptr;
    virtual shc::EResult Compile(String const& src,
                                 ShaderDesc const& inOp,
                                 ShaderBundle& bundle) = 0;
    virtual ~IShCompiler() {}
  };

  class IShModule : public ::k3d::IModule
  {
  public:
    virtual ~IShModule() {}
    virtual IShCompiler::Ptr CreateShaderCompiler(ERHIType const&) = 0;
    // virtual ::k3d::DynArray<String> ListAvailableShaderLanguage() const = 0;
  };
}

#if BUILD_STATIC_PLUGIN
K3D_STATIC_MODULE_DECLARE(ShaderCompiler);
#endif