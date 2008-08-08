/*
 * wrapping of libc features and kernel interfaces
 *
 * Copyright (C) 2005-2008 Kay Sievers <kay.sievers@vrfy.org>
 *
 *	This program is free software; you can redistribute it and/or modify it
 *	under the terms of the GNU General Public License as published by the
 *	Free Software Foundation version 2 of the License.
 * 
 *	This program is distributed in the hope that it will be useful, but
 *	WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *	General Public License for more details.
 * 
 *	You should have received a copy of the GNU General Public License along
 *	with this program; if not, write to the Free Software Foundation, Inc.,
 *	51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#ifndef _UDEV_SYSDEPS_H_
#define _UDEV_SYSDEPS_H_

#include <stdint.h>

/* needed for our signal handlers to work */
#undef asmlinkage
#ifdef __i386__
#define asmlinkage	__attribute__((regparm(0)))
#else
#define asmlinkage
#endif /* __i386__ */

#ifndef HAVE_INOTIFY
static inline int inotify_init(void)
{
	return -1;
}

static inline int inotify_add_watch(int fd, const char *name, uint32_t mask)
{
	return -1;
}

#define IN_CREATE	0
#define IN_DELETE	0
#define IN_MOVE		0
#define IN_CLOSE_WRITE	0

#endif

#ifndef HAVE_STRLCPY
extern size_t strlcpy(char *dst, const char *src, size_t size);
extern size_t strlcat(char *dst, const char *src, size_t size);
#endif

#endif
