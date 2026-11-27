
/*
 * ---- SukiSU-Nova compat declarations for susfs v2.3.0 (Non-GKI 4.14) ----
 * Appended by CI to include/linux/susfs.h (before its final #endif).
 * Only symbols that BOTH the SukiSU tree and the uwu-a17 kernel tree lack.
 * Everything else (susfs_set_sid / is_sid_equal / get_sid_from_name /
 * get_current_sid / is_current_zygote_domain / is_current_zygote_next_domain /
 * is_current_ksu_domain / is_current_init_domain / set_batch_sid /
 * starts_with) already has a real definition and MUST NOT be shimmed.
 */
void susfs_set_current_proc_no_su(void);
void susfs_set_current_proc_umounted_for_zygote_next(void);

int susfs_io(void __user *arg);
int susfs_wipe(void __user *arg);
int susfs_apply_forced(void *arg);

int susfs_add_sus_type(const char *secctx, u32 type_value);
int susfs_add_sus_avd_allowed_by_type(u32 s_type, u32 t_type, u16 type,
				      u32 orig_avd_allowed);
void susfs_set_priority_uid_filter(void __user **user_info);
int susfs_parse_priority_app_strings(const char *str);

bool susfs_ends_with(const char *s, const char *suffix);
bool susfs_starts_with(const char *s, const char *prefix);   /* impl exists in fs/susfs.c:42 */

int ksu_handle_stat_raw(int *dfd, const char __user **filename_user, int *flags);
int ksu_handle_faccessat_raw(int *dfd, const char __user **filename_user,
			     int *mode, int *__unused_flags);
