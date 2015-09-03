#include "toType.h"
#include <mongoc.h>
mongoc_collection_t* mongo_connect (int port, char *db_name, char *collection_name);
//mongoc_client_t* mongo_connect (int port);
//int mongo_insert(char *scolumn,Gais_Data import,char *data, mongoc_collection_t *collection, char *result, char *db_name, char *collection_name, char *action);
//int mongo_insert(char *scolumn,Gais_Data import,char *data, mongoc_collection_t *collection, char *action)
//int mongo_insert(char *scolumn,Gais_Data import,char *data, mongoc_client_t *client, char *result, char *db_name, char *collection_name, char *action);
//int run_command (char *result, char *db_name, char *collection_name, char *action);
int run_command (mongoc_collection_t *collection, char *result, char *db_name, char *collection_name, char *action);
//int run_command (mongoc_client_t *client, char *result, char *db_name, char *collection_name, char *action);
//int mongo_insert(char *scolumn,Gais_Data import,char *data ,mongoc_collection_t *collection, char *result, char *db_name, char *collection_name, char *action);
//int mongo_insert(char *scolumn,Gais_Data import,char *data ,mongoc_client_t *client, char *result, char *db_name, char *collection_name, char *action);
