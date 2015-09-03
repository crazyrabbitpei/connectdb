#include "mongodb.h"
#include <bson.h>
#include <bcon.h>
#include <mongoc.h>
#include <stdio.h>

mongoc_collection_t* mongo_connect (int port, char *db_name, char *collection_name)
//mongoc_client_t* mongo_connect (int port)
{
	mongoc_client_t *client;
	mongoc_collection_t *collection;
	bson_error_t error;
	char uristr[30];
	
	sprintf(uristr,"mongodb://localhost:%d",port);
	
	mongoc_init ();
	client = mongoc_client_new (uristr);
	collection = mongoc_client_get_collection (client, db_name, collection_name);

	if (!client) {
		fprintf (stderr, "Failed to parse URI.\n");
		return NULL;
	}
	return collection;
}
