#pragma once
#include<string>
#include<iostream>
using namespace std;

void contarVocales(string& texto, int pos, int vocales[5])
{
	if (pos >= texto.size())
	{
		return;
	}

	char c = tolower(texto[pos]);
	switch (c)
	{
	case 'a':vocales[0]++; break;
	case 'e':vocales[1]++; break;
	case 'i':vocales[2]++; break;
	case 'o':vocales[3]++; break;
	case 'u':vocales[4]++; break;
	}
	contarVocales(texto, pos + 1, vocales);
}

char determinarVocal(int vocales[5])
{
	int maxPos = 0;
	for (int i = 1; i < 5; i++)
	{
		if (vocales[i] > vocales[maxPos]) {
			maxPos = i;
		}
	}
	return "aeiou"[maxPos];
}