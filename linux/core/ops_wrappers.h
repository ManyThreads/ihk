/**
 * \file ops_wrappers.h
 * \brief IHK-Host:
 *        Macros to generate static functions that invoke "*_ops" functions.
 *
 * All the function is prefixed with "__ihk_device_" or "__ihk_os_".
 *
 * Copyright (c) 2011-2012 Taku Shimosawa <shimosawa@is.s.u-tokyo.ac.jp>
 */
#ifndef __HEADER_IHK_OPS_WRAPPERS_H
#define __HEADER_IHK_OPS_WRAPPERS_H

#include "host_linux.h"

#define IHK_DEV_OPS_BEGIN(rettype, name, ...) \
	static rettype __ihk_device_##name(struct ihk_host_linux_device_data *\
	                                   data, \
	                                   __VA_ARGS__)

#define IHK_OS_OPS_BEGIN(rettype, name, ...) \
	static rettype __ihk_os_##name(struct ihk_host_linux_os_data *data, \
	                               __VA_ARGS__)

#define IHK_OS_OPS_BEGIN_NOARG(rettype, name) \
	static rettype __ihk_os_##name(struct ihk_host_linux_os_data *data)

#define IHK_OPS_BODY(name, ...)	  \
	do { \
	if (data->ops->name) { \
		return data->ops->name(data, data->priv, __VA_ARGS__); \
	} else { \
		return -EINVAL; \
	} \
	} while (0)

#define IHK_OPS_BODY_PTR(name, ...)	  \
	do { \
	if (data->ops->name) { \
		return data->ops->name(data, data->priv, __VA_ARGS__); \
	} else { \
		return NULL; \
	} \
	} while (0)

#define IHK_OPS_BODY_NOARG(name)	  \
	do { \
	if (data->ops->name) { \
		return data->ops->name(data, data->priv); \
	} else { \
		return -EINVAL; \
	} \
	} while (0)

#define IHK_OPS_BODY_PTR_NOARG(name)	  \
	do { \
	if (data->ops->name) { \
		return data->ops->name(data, data->priv); \
	} else { \
		return NULL; \
	} \
	} while (0)

#define IHK_OPS_BODY_VOID(name, ...)	  \
	do { \
	if (data->ops->name) { \
		return data->ops->name(data, data->priv, __VA_ARGS__); \
	} while (0)

IHK_OS_OPS_BEGIN(unsigned long, map_memory,
                 unsigned long rphys, unsigned long size)
{
	IHK_OPS_BODY(map_memory, rphys, size);
}

IHK_OS_OPS_BEGIN(int, unmap_memory, unsigned long lphys, unsigned long size)
{
	IHK_OPS_BODY(unmap_memory, lphys, size);
}

IHK_OS_OPS_BEGIN(int, register_handler, int itype,
                 struct ihk_host_interrupt_handler *h)
{
	IHK_OPS_BODY(register_handler, itype, h);
}

IHK_OS_OPS_BEGIN(int, unregister_handler, int itype,
                 struct ihk_host_interrupt_handler *h)
{
	IHK_OPS_BODY(unregister_handler, itype, h);
}

IHK_OS_OPS_BEGIN(int, alloc_resource, struct ihk_resource *resource)
{
	IHK_OPS_BODY(alloc_resource, resource);
}

IHK_OS_OPS_BEGIN(int, get_special_addr, enum ihk_special_addr_type type,
                 unsigned long *address, unsigned long *size)
{
	IHK_OPS_BODY(get_special_addr, type, address, size);
}

IHK_OS_OPS_BEGIN(int, wait_for_status, enum ihk_os_status status,
                 int sleepable, int timeout)
{
	IHK_OPS_BODY(wait_for_status, status, sleepable, timeout);
}

IHK_OS_OPS_BEGIN(int, issue_interrupt, int cpu, int vector)
{
	IHK_OPS_BODY(issue_interrupt, cpu, vector);
}

IHK_OS_OPS_BEGIN_NOARG(struct ihk_mem_info *, get_memory_info)
{
	IHK_OPS_BODY_PTR_NOARG(get_memory_info);
}

IHK_OS_OPS_BEGIN_NOARG(struct ihk_cpu_info *, get_cpu_info)
{
	IHK_OPS_BODY_PTR_NOARG(get_cpu_info);
}

IHK_OS_OPS_BEGIN_NOARG(int, query_status)
{
	IHK_OPS_BODY_NOARG(query_status);
}

IHK_DEV_OPS_BEGIN(unsigned long, map_memory,
                 unsigned long rphys, unsigned long size)
{
	IHK_OPS_BODY(map_memory, rphys, size);
}

IHK_DEV_OPS_BEGIN(int, unmap_memory, unsigned long lphys, unsigned long size)
{
	IHK_OPS_BODY(unmap_memory, lphys, size);
}

IHK_DEV_OPS_BEGIN(void *, map_virtual, unsigned long phys, unsigned long size,
                  void *virtual, int flags)
{
	IHK_OPS_BODY_PTR(map_virtual, phys, size, virtual, flags);
}

IHK_DEV_OPS_BEGIN(int, unmap_virtual, void *virtual, int flags)
{
	IHK_OPS_BODY(unmap_virtual, virtual, flags);
}

IHK_DEV_OPS_BEGIN(ihk_dma_channel_t, get_dma_channel, int channel)
{
	IHK_OPS_BODY_PTR(get_dma_channel, channel);
}
IHK_DEV_OPS_BEGIN(int, get_dma_info, struct ihk_dma_info *info)
{
	IHK_OPS_BODY(get_dma_info, info);
}

#endif
