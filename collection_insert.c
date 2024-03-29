#include "mongodb.h"
#include "toType.h"
#include <bson.h>
#include <mongoc.h>
#include <stdio.h>

int mongo_insert(char *scolumn,Gais_Data import,char *data, mongoc_collection_t *collection, char *action)
//int mongo_insert(char *scolumn,Gais_Data import,char *data, mongoc_collection_t *collection, char *result, char *db_name, char *collection_name, char *action)
//int mongo_insert(char *scolumn,Gais_Data import,char *data, mongoc_client_t *client, char *result, char *db_name, char *collection_name, char *action)
{
	//mongoc_collection_t *collection;
	mongoc_cursor_t *cursor;
	bson_error_t error;
	bson_oid_t oid;
	bson_t *doc;

	//collection = mongoc_client_get_collection (client, db_name, collection_name);

	doc = bson_new ();
	bson_oid_init (&oid, NULL);
	BSON_APPEND_OID (doc, "_id", &oid);
	BSON_APPEND_UTF8 (doc, "hello", "world");

	if (!mongoc_collection_insert (collection, MONGOC_INSERT_NONE, doc, NULL, &error)) {
		printf ("%s\n", error.message);
	}

	bson_destroy (doc);
	//mongoc_collection_destroy (collection);
	//mongoc_client_destroy (client);

	return 0;
}
