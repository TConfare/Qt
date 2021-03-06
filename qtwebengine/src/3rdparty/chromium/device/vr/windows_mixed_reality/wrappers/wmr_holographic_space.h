// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
#ifndef DEVICE_VR_WINDOWS_MIXED_REALITY_WRAPPERS_WMR_HOLOGRAPHIC_SPACE_H_
#define DEVICE_VR_WINDOWS_MIXED_REALITY_WRAPPERS_WMR_HOLOGRAPHIC_SPACE_H_

#include <windows.graphics.holographic.h>
#include <wrl.h>

#include <memory>

#include "base/macros.h"

namespace device {
class WMRHolographicFrame;
class WMRHolographicSpace {
 public:
  virtual ~WMRHolographicSpace() = default;

  virtual ABI::Windows::Graphics::Holographic::HolographicAdapterId
  PrimaryAdapterId() = 0;
  virtual std::unique_ptr<WMRHolographicFrame> TryCreateNextFrame() = 0;
  virtual bool TrySetDirect3D11Device(
      const Microsoft::WRL::ComPtr<
          ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice>&
          device) = 0;
};

class WMRHolographicSpaceImpl : public WMRHolographicSpace {
 public:
  explicit WMRHolographicSpaceImpl(
      Microsoft::WRL::ComPtr<
          ABI::Windows::Graphics::Holographic::IHolographicSpace> space);
  ~WMRHolographicSpaceImpl() override;

  ABI::Windows::Graphics::Holographic::HolographicAdapterId PrimaryAdapterId()
      override;
  std::unique_ptr<WMRHolographicFrame> TryCreateNextFrame() override;
  bool TrySetDirect3D11Device(
      const Microsoft::WRL::ComPtr<
          ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice>& device)
      override;

 private:
  Microsoft::WRL::ComPtr<ABI::Windows::Graphics::Holographic::IHolographicSpace>
      space_;

  DISALLOW_COPY_AND_ASSIGN(WMRHolographicSpaceImpl);
};

}  // namespace device

#endif  // DEVICE_VR_WINDOWS_MIXED_REALITY_WRAPPERS_WMR_HOLOGRAPHIC_SPACE_H_
