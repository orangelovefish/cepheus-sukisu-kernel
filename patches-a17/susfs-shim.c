
/*
 * ---- SukiSU-Nova compat shims for susfs v2.3.0 (Non-GKI 4.14) ----
 * Appended by CI to fs/susfs.c. Only symbols absent from BOTH trees.
 */
#include <linux/sched.h>
#include <linux/cred.h>
#include <linux/string.h>
#include <linux/errno.h>
#include <linux/uaccess.h>

/* proc-state markers (no equivalent in this tree) */
void susfs_set_current_proc_no_su(void) { }
void susfs_set_current_proc_umounted_for_zygote_next(void) { }

/* extension ioctls: KPM/extension disabled */
int susfs_io(void __user *arg) { return -EOPNOTSUPP; }
int susfs_wipe(void __user *arg) { return -EOPNOTSUPP; }
int susfs_apply_forced(void *arg) { return -EOPNOTSUPP; }

/* SELinux policy helpers referenced by SukiSU sepolicy.c */
int susfs_add_sus_type(const char *secctx, u32 type_value) { return 0; }
int susfs_add_sus_avd_allowed_by_type(u32 s_type, u32 t_type, u16 type,
				      u32 orig_avd_allowed) { return 0; }
void susfs_set_priority_uid_filter(void __user **user_info) { }
int susfs_parse_priority_app_strings(const char *str) { return 0; }

/* real suffix helper (NULL + length safe; strncmp-style, no overread) */
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
