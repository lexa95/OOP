#pragma once

using namespace std;

bool ReadFromFile(set<string> & database, string fileName, void(*ProcessLine)(set<string> & database, string name));
void AddNameToSet(set<string> & database, string name);
