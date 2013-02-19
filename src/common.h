/*
 * Copyright (C) 2004 Jesus Gimenez, Lluis Marquez and Senen Moya
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef COMMON_H

#include <time.h>
#include <sys/times.h>
#include "list.h"
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define CLOCKS_PER_SECOND  sysconf(_SC_CLK_TCK)
#define TRUE	1
#define FALSE	0
#define	KNOWN	11
#define	UNKNOWN	22
#define LEFT_TO_RIGHT		1
#define RIGHT_TO_LEFT		2
#define LR_AND_RL		3

#define TAM_MARK  10
#define TAM_POS   10
#define TAM_WORD  100
#define TAM_LINE  200

#define RM_MODEL_FILES 1001
#define RM_TEMP_FILES  1002

struct nodo_feature_list
{
  nodo_feature_list() :
      mark(),
      l()
  {
  }
  /* the type of the feature. see marks.h for different types */
  std::string mark;
  /* words concerned, eg. (-2, -1, 0) */
  simpleList<int*> l;
};


FILE *openFile(const std::string& name, const char mode[]);
void generateFileName(const std::string& name, const std::string& added, int numModel, int direction, int what, const std::string& type, string& out);

void showProcessDone(int num,int freq, int isEnd, const std::string& what);
void showProcess(int num, int isEnd);
//void showTime(char *what, clock_t start,clock_t end, struct tms tbuff1,struct tms tbuff2);
void showTime(const std::string& what, double real, double utime,double stime);

int goToWord(FILE *f, int offset);

int readString(FILE* f, string& out);
int readTo(FILE* f, char endChar, char endLine, string& out);
//void saltarLinea(FILE *f);

void qsort(int a[], int lo, int hi);

int ordenarStringPorParejas(const char* szIn, char* szOut, int depth, char* szInicial);

void destroyFeatureList(simpleList<nodo_feature_list*> *);
void createFeatureList(const std::string& name,simpleList<nodo_feature_list*> *featureList);
void removeFiles(const std::string& path, int type,int numModel, int direction, int verbose);
void Tokenize(const string& str, vector<string>& tokens, const string& delimiters);


#define COMMON_H
#endif
