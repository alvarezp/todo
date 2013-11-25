// Abimael Martell @ 2013

#include "todo.h"

char *todo_findAll(){
  sqlite3_stmt *stmt;
  json_object *todos, *todo, *id, *text, *status;
  int rc;

  sqlite3 *db = getSQLConn();
  todos = json_object_new_array();

  char sql[] = "SELECT * FROM todos";
  rc = sqlite3_prepare_v2(db, sql, sizeof(sql), &stmt, NULL);
  while(sqlite3_step(stmt) == SQLITE_ROW){
    todo = json_object_new_object();
    id = json_object_new_int(sqlite3_column_int(stmt, 0));
    text = json_object_new_string((const char *)sqlite3_column_text(stmt, 1));
    status = json_object_new_int(sqlite3_column_int(stmt, 2));

    json_object_object_add(todo, "id", id);
    json_object_object_add(todo, "text", text);
    json_object_object_add(todo, "status", status);

    json_object_array_add(todos, todo);
  }

  sqlite3_close(db);
  return strdup(json_object_to_json_string(todos));
}

int todo_create(char *text){
  char sql[1000], *errBuf;
  int rc;

  sqlite3 *db = getSQLConn();

  sprintf(sql, "INSERT INTO todos (text) VALUES ('%s')", text);

  rc = sqlite3_exec(db, sql, NULL, NULL, &errBuf);

  if(rc != SQLITE_OK){
    printf("SQL Error: %s\n", errBuf);
    return 1;
  }

  sqlite3_close(db);
  return 0;
}