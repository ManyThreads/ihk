#ifndef __HEADER_GENERIC_AAL_MM_H
#define __HEADER_GENERIC_AAL_MM_H

#include <memory.h>

enum aal_mc_gma_type {
	AAL_MC_GMA_MAP_START,
	AAL_MC_GMA_MAP_END,
	AAL_MC_GMA_AVAIL_START,
	AAL_MC_GMA_AVAIL_END,
	AAL_MC_GMA_HEAP_START,
};

enum aal_mc_ma_type {
	AAL_MC_MA_AVAILABLE,
	AAL_MC_MA_RESERVED,
	AAL_MC_MA_SPECIAL,
};

enum aal_mc_ap_flag {
	AAL_MC_AP_FLAG,
};

struct aal_mc_memory_area {
	unsigned long start;
	unsigned long size;
	enum aal_mc_ma_type type;
};

struct aal_mc_memory_node {
	int node;
	int nareas;
	struct aal_mc_memory_area *areas;
};

unsigned long aal_mc_get_memory_address(enum aal_mc_gma_type, int);

void aal_mc_reserve_arch_pages(unsigned long start, unsigned long end,
                               void (*cb)(unsigned long, unsigned long, int));

struct aal_mc_pa_ops {
	void *(*alloc)(int, enum aal_mc_ap_flag);
	void (*free)(void *, int);
};

void aal_mc_set_page_allocator(struct aal_mc_pa_ops *);
void aal_mc_set_page_fault_handler(void (*h)(unsigned long, void *));

unsigned long aal_mc_map_memory(void *os, unsigned long phys, 
                                unsigned long size);
void aal_mc_unmap_memory(void *os, unsigned long phys, unsigned long size);

void *aal_mc_map_virtual(unsigned long phys, int npages,
                         enum aal_mc_pt_attribute attr);
void aal_mc_unmap_virtual(void *va, int npages);

void *aal_mc_alloc_pages(int npages, enum aal_mc_ap_flag flag);
void aal_mc_free_pages(void *p, int npages);

void *arch_alloc_page(enum aal_mc_ap_flag flag);
void arch_free_page(void *ptr);

typedef void *page_table_t;

int aal_mc_pt_set_page(page_table_t pt, void *virt, unsigned long phys,
                       enum aal_mc_pt_attribute attr);
int aal_mc_pt_change_page(page_table_t pt, void *virt,
                          enum aal_mc_pt_attribute);
int aal_mc_pt_clear_page(page_table_t pt, void *virt);


#endif
