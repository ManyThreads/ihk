/**
 * \file mic_user.h
 * \brief IHK MIC Driver: Definitions of MIC-specific ioctl constants
 */
#ifndef __MIC_USER_H
#define __MIC_USER_H

#include <ihk/ihk_host_user.h>

#define MIC_DEBUG_READ_SCRATCH  (IHK_DEVICE_DEBUG_START + 0)
#define MIC_DEBUG_READ_SBOX     (IHK_DEVICE_DEBUG_START + 1)
#define MIC_DEBUG_DMA_TEST      (IHK_DEVICE_DEBUG_START + 10)

#endif
