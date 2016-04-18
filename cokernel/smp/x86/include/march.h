#ifndef __HEADER_IHK_BUILTIN_MARCH
#define __HEADER_IHK_BUILTIN_MARCH

#define LAPIC_ID_SHIFT     24
#define LAPIC_ICR_ID_SHIFT 24

#define X86_IA32_NUM_PERF_COUNTERS 4
#define X86_IA32_NUM_FIXED_PERF_COUNTERS  3
#define X86_IA32_BASE_FIXED_PERF_COUNTERS 32
#define X86_IA32_PERF_COUNTERS_MASK       0x0000000f
#define X86_IA32_FIXED_PERF_COUNTERS_MASK 0x700000000

#define	MSR_IA32_TIME_STAMP_COUNTER	0x00000010 /* TSC */
#define MSR_IA32_PMC0        0x000000c1
#define MSR_IA32_PERFEVTSEL0 0x00000186
#define MSR_IA32_FIXED_CTR0  0x00000309
#define MSR_PERF_FIXED_CTRL  0x0000038d
#define MSR_PERF_GLOBAL_STATUS       0x0000038e
#define MSR_PERF_GLOBAL_CTRL 0x0000038f
#define MSR_PERF_GLOBAL_OVF_CTRL     0x00000390

#define ENABLE_SSE

#endif
