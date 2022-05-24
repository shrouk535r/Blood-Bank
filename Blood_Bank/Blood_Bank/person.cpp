#include "person.h"
bool person::isValidmail(const string& email)
{

	// Regular expression definition
	const regex pattern(
		"(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

	// Match the string pattern
	// with regular expression
	return regex_match(email, pattern);
}
