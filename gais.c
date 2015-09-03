#include <bson.h>
#include <bcon.h>
#include "mongodb.h"
#include <mongoc.h>
#include <stdio.h>
#define RESULT_LEN 100000
int main (int  argc, char *argv[])
{
	char db_name[100]="test2";
	char collection_name[100]="students";
	/*
	char db_name2[100]="test";
	char collection_name2[100]="OceanTest_mongo";
	*/

	char action[20]="collStats";
	char *result;
	mongoc_collection_t *collection, *collection2;

	Gais_Data import;
	//mongoc_client_t *client;
	/*connect to db*/
	collection = mongo_connect(27017,db_name,collection_name);
	//collection2 = mongo_connect(27017,db_name2,collection_name2);
	//client = mongo_connect(27017);
	/*show collection's state*/
	result = malloc(sizeof(char)*RESULT_LEN);
	//run_command(result,db_name,collection_name,action);
	run_command(collection,result,db_name,collection_name,action);
	printf("\n%s\n",result);
	free(result);
	
	/*
	result = malloc(sizeof(char)*RESULT_LEN);
	run_command(collection2,result,db_name2,collection_name2,action);
	//run_command(client,result,db_name,collection_name,action);
	printf("\n2.%s\n",result);
	free(result);
	*/

	/*mongo_insert*/
	//strcpy(import.lan,"CHT");
        //strcpy(import.author,"me");
	
	//mongo_insert(0,import,"hello mongodb",collection,0);	

	mongoc_cleanup ();

	return 0;
}

