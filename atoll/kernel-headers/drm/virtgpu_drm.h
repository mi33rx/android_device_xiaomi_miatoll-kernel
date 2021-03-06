/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef VIRTGPU_DRM_H
#define VIRTGPU_DRM_H
#include "drm.h"
#ifdef __cplusplus
extern "C" {
#endif
#define DRM_VIRTGPU_MAP 0x01
#define DRM_VIRTGPU_EXECBUFFER 0x02
#define DRM_VIRTGPU_GETPARAM 0x03
#define DRM_VIRTGPU_RESOURCE_CREATE 0x04
#define DRM_VIRTGPU_RESOURCE_INFO 0x05
#define DRM_VIRTGPU_TRANSFER_FROM_HOST 0x06
#define DRM_VIRTGPU_TRANSFER_TO_HOST 0x07
#define DRM_VIRTGPU_WAIT 0x08
#define DRM_VIRTGPU_GET_CAPS 0x09
#define DRM_VIRTGPU_RESOURCE_CREATE_BLOB 0x0a
#define VIRTGPU_EXECBUF_FENCE_FD_IN 0x01
#define VIRTGPU_EXECBUF_FENCE_FD_OUT 0x02
#define VIRTGPU_EXECBUF_FLAGS (VIRTGPU_EXECBUF_FENCE_FD_IN | VIRTGPU_EXECBUF_FENCE_FD_OUT | 0)
struct drm_virtgpu_map {
  __u64 offset;
  __u32 handle;
  __u32 pad;
};
struct drm_virtgpu_execbuffer {
  __u32 flags;
  __u32 size;
  __u64 command;
  __u64 bo_handles;
  __u32 num_bo_handles;
  __s32 fence_fd;
};
#define VIRTGPU_PARAM_3D_FEATURES 1
#define VIRTGPU_PARAM_CAPSET_QUERY_FIX 2
#define VIRTGPU_PARAM_RESOURCE_BLOB 3
#define VIRTGPU_PARAM_HOST_VISIBLE 4
struct drm_virtgpu_getparam {
  __u64 param;
  __u64 value;
};
struct drm_virtgpu_resource_create {
  __u32 target;
  __u32 format;
  __u32 bind;
  __u32 width;
  __u32 height;
  __u32 depth;
  __u32 array_size;
  __u32 last_level;
  __u32 nr_samples;
  __u32 flags;
  __u32 bo_handle;
  __u32 res_handle;
  __u32 size;
  __u32 stride;
};
struct drm_virtgpu_resource_info {
  __u32 bo_handle;
  __u32 res_handle;
  __u32 size;
  union {
    __u32 stride;
    __u32 strides[4];
  };
  __u32 num_planes;
  __u32 offsets[4];
  __u64 format_modifier;
};
struct drm_virtgpu_3d_box {
  __u32 x;
  __u32 y;
  __u32 z;
  __u32 w;
  __u32 h;
  __u32 d;
};
struct drm_virtgpu_3d_transfer_to_host {
  __u32 bo_handle;
  struct drm_virtgpu_3d_box box;
  __u32 level;
  __u32 offset;
};
struct drm_virtgpu_3d_transfer_from_host {
  __u32 bo_handle;
  struct drm_virtgpu_3d_box box;
  __u32 level;
  __u32 offset;
};
#define VIRTGPU_WAIT_NOWAIT 1
struct drm_virtgpu_3d_wait {
  __u32 handle;
  __u32 flags;
};
struct drm_virtgpu_get_caps {
  __u32 cap_set_id;
  __u32 cap_set_ver;
  __u64 addr;
  __u32 size;
  __u32 pad;
};
struct drm_virtgpu_resource_create_blob {
#define VIRTGPU_BLOB_MEM_GUEST 0x0001
#define VIRTGPU_BLOB_MEM_HOST 0x0002
#define VIRTGPU_BLOB_MEM_HOST_GUEST 0x0003
#define VIRTGPU_BLOB_FLAG_MAPPABLE 0x0001
#define VIRTGPU_BLOB_FLAG_SHAREABLE 0x0002
#define VIRTGPU_BLOB_FLAG_CROSS_DEVICE 0x0004
  __u32 blob_mem;
  __u32 blob_flags;
  __u32 bo_handle;
  __u32 res_handle;
  __u64 size;
  __u32 pad;
  __u32 cmd_size;
  __u64 cmd;
  __u64 blob_id;
};
#define DRM_IOCTL_VIRTGPU_MAP DRM_IOWR(DRM_COMMAND_BASE + DRM_VIRTGPU_MAP, struct drm_virtgpu_map)
#define DRM_IOCTL_VIRTGPU_EXECBUFFER DRM_IOWR(DRM_COMMAND_BASE + DRM_VIRTGPU_EXECBUFFER, struct drm_virtgpu_execbuffer)
#define DRM_IOCTL_VIRTGPU_GETPARAM DRM_IOWR(DRM_COMMAND_BASE + DRM_VIRTGPU_GETPARAM, struct drm_virtgpu_getparam)
#define DRM_IOCTL_VIRTGPU_RESOURCE_CREATE DRM_IOWR(DRM_COMMAND_BASE + DRM_VIRTGPU_RESOURCE_CREATE, struct drm_virtgpu_resource_create)
#define DRM_IOCTL_VIRTGPU_RESOURCE_INFO DRM_IOWR(DRM_COMMAND_BASE + DRM_VIRTGPU_RESOURCE_INFO, struct drm_virtgpu_resource_info)
#define DRM_IOCTL_VIRTGPU_TRANSFER_FROM_HOST DRM_IOWR(DRM_COMMAND_BASE + DRM_VIRTGPU_TRANSFER_FROM_HOST, struct drm_virtgpu_3d_transfer_from_host)
#define DRM_IOCTL_VIRTGPU_TRANSFER_TO_HOST DRM_IOWR(DRM_COMMAND_BASE + DRM_VIRTGPU_TRANSFER_TO_HOST, struct drm_virtgpu_3d_transfer_to_host)
#define DRM_IOCTL_VIRTGPU_WAIT DRM_IOWR(DRM_COMMAND_BASE + DRM_VIRTGPU_WAIT, struct drm_virtgpu_3d_wait)
#define DRM_IOCTL_VIRTGPU_GET_CAPS DRM_IOWR(DRM_COMMAND_BASE + DRM_VIRTGPU_GET_CAPS, struct drm_virtgpu_get_caps)
#define DRM_IOCTL_VIRTGPU_RESOURCE_CREATE_BLOB DRM_IOWR(DRM_COMMAND_BASE + DRM_VIRTGPU_RESOURCE_CREATE_BLOB, struct drm_virtgpu_resource_create_blob)
#ifdef __cplusplus
}
#endif
#endif
