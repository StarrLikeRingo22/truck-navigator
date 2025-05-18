#pragma once
#ifndef UNITTESTS_R_H
#define UNITTESTS_R_H

extern "C"
{
#include <mapping.h> // may cause error (file not found)
#include <mapping.c> // configure UnitTest properties to include SourceCode file
#include <truck.h>
#include <truck.c>
}

#endif
