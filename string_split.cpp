/*
Copyright © 2014 Craig Lilley <cralilley@gmail.com>
This work is free. You can redistribute it and/or modify it under the
terms of the Do What The Fuck You Want To Public License, Version 2,
as published by Sam Hocevar. See http://www.wtfpl.net/ for more details.
*/
 
#include <vector>
#include <string>

using std::vector;
using std::string;

vector<string> split(const string& string_to_split, const string& delimeter)
{
    vector<string> result;

    size_t pos = string_to_split.find(delimeter);

    size_t substr_start_pos = 0;

    while( pos != std::string::npos )
    {
        string substr = string_to_split.substr(substr_start_pos, pos - substr_start_pos);

        result.push_back( substr );

        substr_start_pos = pos + delimeter.length();

        pos = string_to_split.find(delimeter, substr_start_pos);
    }

    string final_substr = string_to_split.substr(substr_start_pos, pos);

    result.push_back( final_substr );

    return result;
}