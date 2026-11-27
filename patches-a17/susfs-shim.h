
/*
 * ---- SukiSU-Nova compat declarations for susfs v2.3.0 (Non-GKI 4.14) ----
 * Appended by CI to include/linux/susfs.h so every SukiSU call site sees
 * a prototype (avoids -Werror,-Wimplicit-function-declaration).
 * Implementations live in the CI-appended block at the end of fs/susfs.c.
 */
void susfs_set_current_proc_no_su(void);
void susfs_set_current_proc_umounted_for_zygote_next(void);

bool susfs_is_current_zygote_domain(void);
bool susfs_is_current_zygote_next_domain(void);
bool susfs_is_current_init_domain(void);
bool susfs_is_sid_equal(const void *a, const void *b);

int susfs_get_current_sid(void);
int susfs_get_sid_from_name(const char *name);
int susfs_init_sid(void);
void susfs_set_sid(void __user **user_info);
void susfs_set_batch_sid(void __user **user_info);

int susfs_io(void __user *arg);
int susfs_wipe(void __user *arg);
int susfs_apply_forced(void *arg);

int susfs_add_sus_type(const char *secctx, u32 type_value);
int susfs_add_sus_avd_allowed_by_type(u32 s_type, u32 t_type, u16 type,
				       u32 orig_avd_allowed);
void susfs_set_priority_uid_filter(void __user **user_info);
int susfs_parse_priority_app_strings(const char *str);

bool susfs_ends_with(const char *s, const char *suffix);
bool susfs_starts_with(const char *s, const char *prefix);

int ksu_handle_stat_raw(int *dfd, const char __user **filename_user, int *flags);
int ksu_handle_faccessat_raw(int *dfd, const char __user **filename_user,
			     int *mode, int *__unused_flags);
