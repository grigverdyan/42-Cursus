#include "tester.h"

printftest flag_space_type_i_tests[] = {
	{" % i ", 1, "si", {{.i=0}}},
	{" % i ", 1, "si", {{.i=INT_MAX}}},
	{" % i ", 1, "si", {{.i=INT_MIN}}},
	{" % i % i % i ", 3, "siii", {{.i=42},{.i=-42},{.i=249857}}},
	{" % i% i% i ", 3, "siii", {{.i=1234567},{.i=987654},{.i=177013}}},
	{" % i% i% i ", 3, "siii", {{.i=-325972},{.i=-215600}, {.i=-43534534}}},
	{" % i % i % i % i % i % i ", 6, "siiiiii", {{.i=-13475},{.i=2375644},{.i=-32432},{.i=INT_MAX},{.i=INT_MIN},{.i=216500}}}
};

int tests_flag_space_type_i()
{
	return (arraysize(flag_space_type_i_tests));
}

void	test_flag_space_type_i(int n, bool detail)
{
	printftestcore(flag_space_type_i_tests[n], n, detail);
}
