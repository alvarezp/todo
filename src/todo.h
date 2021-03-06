// Abimael Martell @ 2013

#include <stdio.h>
#include <string.h>
#include <mongoose.h>
#include <sqlite3.h>
#include <json.h>
#include <regex.h>

#include "model.h"
#include "actions.h"

#define TODO_CREATE_URL   "/todos"
#define TODO_LIST_URL     "/todos"
#define TODO_UPDATE_REGEX "^\\/todos\\/[[:digit:]]"

#define HTTP_METHOD_HEADER "X-HTTP-Method-Override"

extern sqlite3 *db;
extern struct mg_context *ctx;
extern int event_handler(struct mg_event *event);
extern void initialize(void);
extern void term(void);
