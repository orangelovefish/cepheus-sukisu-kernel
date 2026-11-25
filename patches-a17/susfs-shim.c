
/*
 * ---- SukiSU-Nova compatibility shims for susfs v2.3.0 (Non-GKI 4.14) ----
 * Appended by CI. Provides symbols SukiSU expects but this tree lacks.
 */
#include <linux/sched.h>
#include <linux/cred.h>
#include <linux/string.h>
#include <linux/errno.h>
#include <linux/uaccess.h>

void susfs_set_current_proc_no_su(void) { }
void susfs_set_current_proc_umounted(void) { }
void susfs_set_current_proc_umounted_for_zygote_next(void) { }

bool susfs_is_current_zygote_domain(void) { return false; }
bool susfs_is_current_zygote_next_domain(void) { return false; }
bool susfs_is_current_init_domain(void) { return false; }
bool susfs_is_sid_equal(const void *a, const void *b) { return false; }
int susfs_get_current_sid(void) { return 0; }
int susfs_get_sid_from_name(const char *name) { return 0; }
int susfs_init_sid(void) { return 0; }
void susfs_set_sid(void __user **user_info) { }
void susfs_set_batch_sid(void __user **user_info) { }

int susfs_io(void __user *arg) { return -EOPNOTSUPP; }
int susfs_get(void __user *arg) { return -EOPNOTSUPP; }
int susfs_set(void __user *arg) { return -EOPNOTSUPP; }
int susfs_wipe(void __user *arg) { return -EOPNOTSUPP; }
int susfs_apply_forced(void *arg) { return -EOPNOTSUPP; }

void susfs_add_sus_type(const char *secctx, u32 type_value) { }
void susfs_add_sus_avd_allowed_by_type(u32 s_type, u32 t_type, u16 type, u32 orig_avd_allowed) { }
void susfs_set_priority_uid_filter(void __user **user_info) { }
int susfs_parse_priority_app_strings(const char *str) { return 0; }

bool susfs_ends_with(const char *s, const char *suffix)
{
	size_t ls, lf;
	if (!s || !suffix)
		return false;
	ls = strlen(s);
	lf = strlen(suffix);
	if (lf > ls)
		return false;
	return !strcmp(s + ls - lf, suffix);
}
