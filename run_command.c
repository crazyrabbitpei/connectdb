#include "mongodb.h"
#include <bson.h>
#include <bcon.h>
#include <mongoc.h>
#include <stdio.h>

//int run_command (char *result, char *db_name, char *collection_name, char *action)
int run_command (mongoc_collection_t *collection, char *result, char *db_name, char *collection_name, char *action)
//int run_command (mongoc_client_t *client, char *result, char *db_name, char *collection_name, char *action)
{
	//mongoc_collection_t *collection;
	bson_error_t error;
	bson_t *command;
	bson_t reply;
	char *str;
	
	//collection = mongoc_client_get_collection (client, db_name, collection_name);
	command = BCON_NEW (action, BCON_UTF8 (collection_name));
	if (mongoc_collection_command_simple (collection, command, NULL, &reply, &error)) {
		str = bson_as_json (&reply, NULL);
		sprintf(result,"%s",str);
		bson_free (str);
	} else {
		fprintf (stderr, "Failed to run command: %s\n", error.message);
	}

	bson_destroy (command);
	bson_destroy (&reply);
	mongoc_collection_destroy (collection);
	//mongoc_client_destroy (client);
	return 0;
}
