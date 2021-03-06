//
// Bareflank Hypervisor Examples
//
// Copyright (C) 2015 Assured Information Security, Inc.
// Author: Rian Quinn        <quinnr@ainfosec.com>
// Author: Brendan Kerrigan  <kerriganb@ainfosec.com>
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

#include <vcpu/vcpu_factory.h>
#include <vcpu/vcpu_intel_x64.h>
#include <exit_handler_cpuidcount/exit_handler_cpuidcount.h>

std::unique_ptr<vcpu>
vcpu_factory::make_vcpu(vcpuid::type vcpuid, user_data *data)
{
    auto &&my_exit_handler = std::make_unique<exit_handler_cpuidcount>();

    (void) data;
    return std::make_unique<vcpu_intel_x64>(
               vcpuid,
               nullptr,                         // default debug_ring
               nullptr,                         // default vmxon
               nullptr,                         // default vmcs
               std::move(my_exit_handler),
               nullptr,                         // default vmm_state
               nullptr);                        // default guest_state
}
