#include "pch.h"

#include <stdio.h>
#include <string.h>

#define str "1234567890"

TEST(ProCamp_Task_4, Test1) {
	extern void* memcpy(void* dst, const void* src, size_t n);

	char nstr[30] = { 0 };
	strcpy(nstr, str);
	printf("\tBefore memcpy nstr = %s\n", nstr);
	memcpy(nstr, str, strlen(str) + 1);
	printf("\tAfter memcpy nstr = %s\n", nstr);

	ASSERT_STREQ(str, nstr);
	EXPECT_STREQ(str, nstr);
}

TEST(ProCamp_Task_4, Test2) {
	extern void* memcpy(void* dst, const void* src, size_t n);

	char nstr[30] = { 0 };
	strcpy(&nstr[5], str);
	printf("\tBefore memcpy nstr = %s\n", nstr);
	memcpy(nstr, &nstr[5], strlen(nstr) + 1);
	printf("\tAfter memcpy nstr = %s\n", nstr);

	ASSERT_STRNE(str, nstr);
	EXPECT_STRNE(str, nstr);
}

TEST(ProCamp_Task_4, Test3) {
	extern void* memcpy(void* dst, const void* src, size_t n);

	char nstr[30] = { 0 };
	strcpy(&nstr[0], str);
	printf("\tBefore memcpy nstr = %s\n", nstr);
	memcpy(&nstr[5], nstr, strlen(nstr) + 1);
	printf("\tAfter memcpy nstr = %s\n", nstr);

	//ASSERT_STRCASEEQ(nstr, str);
	//EXPECT_STRCASEEQ(nstr, str);

	ASSERT_STRCASENE(str, nstr);
	EXPECT_STRCASENE(str, nstr);
}