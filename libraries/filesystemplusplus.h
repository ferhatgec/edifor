/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef FILE_SYSTEM_PLUS_PLUS_H
#define FILE_SYSTEM_PLUS_PLUS_H

#include <sys/stat.h>

#include <Edifor.h>

/* From my FileSystemPlusPlus library but minimalized & c-compatible */

_bool is_exist(const char* path) {
	struct stat buffer;
	return (stat(path, &buffer) == 0);
}

#endif // FILE_SYSTEM_PLUS_PLUS_H
