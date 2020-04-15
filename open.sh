#!/bin/bash
cd src
vim main.cpp \
	shell.cpp shell.h \
	cmdparser.cpp cmdparser.h \
	command.h command.cpp \
	all_commands.h \
	cmd_cp.h cmd_cp.cpp \
	cmd_cmp.h cmd_cmp.cpp \
	cmd_cat.h cmd_cat.cpp \
	cmd_wc.h cmd_wc.cpp
cd ..
