#pragma once

using namespace std;

string ExpandTemplate(string tpl, map<string, string> params);
string KMP(string const& line, string const& searchString, string const& replacementString, vector<bool> & isReplacement);