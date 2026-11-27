
/*
 * ---- SukiSU-Nova compat shims for susfs v2.3.0 (Non-GKI 4.14) ----
 * Appended by CI to fs/susfs.c. Provides symbols SukiSU expects but the
 * uwu-a17 tree lacks. Prototypes are declared via patches-a17/susfs-shim.h.
 */
#include <linux/sched.h>
#include <linux/cred.h>
#include <linux/string.h>
#include <linux/errno.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

/* --- proc-state helpers --- */
void susfs_set_current_proc_no_su(void) { }
void susfs_set_current_proc_umounted_for_zygote_next(void) { }

/* --- sid / domain helpers --- */
bool susfs_is_current_zygote_domain(void) { return false; }
bool susfs_is_current_zygote_next_domain(void) { return false; }
bool susfs_is_current_init_domain(void) { return false; }
bool susfs_is_sid_equal(const void *a, const void *b) { return false; }
int susfs_get_current_sid(void) { return 0; }
int susfs_get_sid_from_name(const char *name) { return 0; }
int susfs_init_sid(void) { return 0; }
void susfs_set_sid(void __user **user_info) { }
void susfs_set_batch_sid(void __user **user_info) { }

/* --- extension ioctls (KPM disabled => unsupported) --- */
int susfs_io(void __user *arg) { return -EOPNOTSUPP; }
int susfs_wipe(void __user *arg) { return -EOPNOTSUPP; }
int susfs_apply_forced(void *arg) { return -EOPNOTSUPP; }

/* --- policy helpers --- */
int susfs_add_sus_type(const char *secctx, u32 type_value) { return 0; }
int susfs_add_sus_avd_allowed_by_type(u32 s_type, u32 t_type, u16 type,
				       u32 orig_avd_allowed) { return 0; }
void susfs_set_priority_uid_filter(void __user **user_info) { }
int susfs_parse_priority_app_strings(const char *str) { return 0; }

/* --- real string helpers (NULL / length safe) --- */
bool susfs_ends_with(const char *s, const char *suffix)
{
	size_t ls, lf;

	if (!s || !suffix)
		return false;
	ls = strlen(s);
	lf = strlen(suffix);
	if (lf > ls)
		return false;
	return !memcmp(s + ls - lf, suffix, lf);
}

bool susfs_starts_with(const char *s, const char *prefix)
{
	size_t lp;

	if (!s || !prefix)
		return false;
	lp = strlen(prefix);
	return !memcmp(s, prefix, lp);
}
