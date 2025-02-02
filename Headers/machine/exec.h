/*
 * Copyright (c) 2000-2018 Apple Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 *
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */
/*
 * Copyright 1995 NeXT Computer, Inc. All rights reserved.
 */
#ifndef _BSD_MACHINE_EXEC_H_
#define _BSD_MACHINE_EXEC_H_

#include <i386/vmparam.h>
#include <sys/param.h>
#include <stdbool.h>

/*
 * Note: This seems to be XNU's version of the ps_strings structure in other BSDs like FreeBSD and NetBSD.
 *       Thought noting this down could be useful when porting BSD functions that rely on the ps_strings
 *       structure so that we know where to look.
 *
 *       - https://github.com/somestupidgirl
 */
struct exec_info {
	char      path[MAXPATHLEN];
	int       ac;              /* the number of argument strings */
	int       ec;              /* the number of environment strings */
	char    **av;              /* first of 0 or more argument strings */
	char    **ev;              /* first of 0 or more environment strings */
};

/*
 * Note: Macro (PS_STRINGS) ported from NetBSD to complement XNU's exec_info structure.
 *
 *       Address of exec_info structure. We only use this as a default in user space.
 *
 *       - https://github.com/somestupidgirl
 */
#define EXEC_INFO \
    ((struct exec_info *)(USRSTACK - sizeof(struct exec_info)))

#endif /* _BSD_MACHINE_EXEC_H_ */
