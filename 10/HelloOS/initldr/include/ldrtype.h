#ifnef _LDRTYPE_H
#define _LDRTYPE_H

#define BFH_RW_R 1
#define BFH_RW_W 2

#define BFH_BUF_SZ 0x1000
#define BFH_ONERW_SZ 0x1000
#define BFH_RWONE_OK 1
#define BFH_RWONE_ER 2
#define BFH_RWALL_OK 3

#define FHDSC_NMAX 192
#define FHDSC_SZMAX 256
#define MDC_ENDGIC 0xaaffaaffaaffaaff
#define MDC_RVGIC 0xffaaffaaffaaffaa
#define REALDRV_PHYADR 0x1000
#define ILDRKRL_PHYADR 0x200000
#define IMGSHEL_PHYADR 0x30000
#define IKSTACK_PHYADR (0x90000-0x10)
#define IKSTACK_SIZE 0x1000
#define IMGFILE_PHYADR 0x4000000
#define IMGKRNL_PHYADR 0x2000000
#define KINITPAGE_PHYADR 0x1000000
#define KINITFRVM_PHYADR 0x800000
#define KINITFRVM_SZ 0x400000
#define LDRFILEADR IMGFILE_PHYADR
#define MLOSDSC_OFF (0x1000)
#define MRDDSC_ADR (mlosrddsc_t*)(LDRFILEADR+0x1000)

#define KRNL_VIRTUAL_ADDRESS_START 0xffff800000000000
#define KPML4_P (1<<0)
#define KPML4_RW (1<<1)
#define KPML4_US (1<<2)
#define KPML4_PWT (1<<3)
#define KPML4_PCD (1<<4)
#define KPML4_A (1<<5)

#define KPDPTE_P (1<<0)
#define KPDPTE_RW (1<<1)
#define KPDPTE_US (1<<2)
#define KPDPTE_PWT (1<<3)
#define KPDPTE_PCD (1<<4)
#define KPDPTE_A (1<<5)

#define KPDE_P (1<<0)
#define KPDE_RW (1<<1)
#define KPDE_US (1<<2)
#define KPDE_PWT (1<<3)
#define KPDE_PCD (1<<4)
#define KPDE_A (1<<5)
#define KPDE_D (1<<6)
#define KPDE_PS (1<<7)
#define KPDE_G (1<<8)
#define KPDE_PAT (1<<12)

#define KPML4_SHIFT 39
#define KPDPTTE_SHIFT 30
#define KPDP_SHIFT 21
#define PGENTY_SIZE 512

// 文件头描述符
typedef struct s_fhdsc
{
  u64_t fhd_type;// 文件类型
  u64_t fhd_subtype;// 文件符子类型
  u64_t fhd_stuts;// 文件状态
  u64_t fhd_id;// 文件ID
  u64_t fhd_intsfsoff;// 文件在映像文件位置开始偏移
  u64_t fhd_intsfend;// 文件在映像文件的结束偏移
  u64_t fhd_frealsz;// 文件实际大小
  u64_t fhd_fsum;// 文件校验和
  char fhd_name[FHDSC_NMAX];// 文件名
}fhdsc_t;

// 映像文件头描述符
typedef struct s_mlosrddsc
{
  u64_t mdc_mgic;// 映射文件标识
  u64_t mdc_sfsum;// 未使用
  u64_t mdc_sfsoff;// 未使用
  u64_t mdc_sfeoff;// 未使用
  u64_t mdc_sfrlsz;// 未使用
  u64_t mdc_ldrbk_s;// 映射文件中二级引导器的开始偏移
  u64_t mdc_ldrbk_e;// 映射文件中二级引导器的结束偏移
  u64_t mdc_ldrbk_rsz;// 映射文件中二级引导器的实际大小
  u64_t mdc_ldrbk_sum;// 映射文件中二级引导器的校验和
  u64_t mdc_fhdbk_s;// 映射文件中文件头描述符的开始偏移
  u64_t mdc_fhdbk_e;// 映射文件中文件头描述符的结束偏移
  u64_t mdc_fhdbk_rsz;// 映射文件中文件头描述符的实际大小
  u64_t mdc_fhdbk_sum;// 映射文件中文件头描述符的校验和
  u64_t mdc_filbk_s;// 映射文件中文件数据的开始偏移
  u64_t mdc_filbk_e;// 映射文件中文件数据的结束偏移
  u64_t mdc_filbk_rsz;// 映射文件中文件数据的实际大小
  u64_t mdc_filbk_sum;// 映射文件中文件数据的校验和
  u64_t mdc_ldrcodenr;// 映射文件中二级引导器的文件头描述符的索引号
  u64_t mdc_fhdnr;// 映射文件中文件头描述符有多少个
  u64_t mdc_filnr;// 映射文件中文件结束标识
  u64_t mdc_endgic;// 映射文件结束标识
  u64_t mdc_rv;// 映射文件版本
}mlosrddsc_t;

#endif // _LDRTYPE_H
