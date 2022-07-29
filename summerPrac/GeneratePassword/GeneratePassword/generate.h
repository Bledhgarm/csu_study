#pragma once
#include "config.h"

int error(char* str);
void generatePassword(struct config* conf);
int getPasswordLength(struct config* conf);