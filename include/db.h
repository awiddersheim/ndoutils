/**
 * @file db.h Database declarations for ndo2db daemon
 */
/*
 * Copyright 2009-2014 Nagios Core Development Team and Community Contributors
 * Copyright 2005-2009 Ethan Galstad
 *
 * This file is part of NDOUtils.
 *
 * NDOUtils is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * NDOUtils is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with NDOUtils. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _NDO2DB_DB_H
#define _NDO2DB_DB_H

#include "config.h"
#include "ndo2db.h"

typedef struct ndo2db_dbconfig {
	int server_type;
	int port;
	char *host;
	char *socket;
	char *username;
	char *password;
	char *dbname;
	char *dbprefix;
	unsigned long max_timedevents_age;
	unsigned long max_systemcommands_age;
	unsigned long max_servicechecks_age;
	unsigned long max_hostchecks_age;
	unsigned long max_eventhandlers_age;
	unsigned long max_externalcommands_age;
	unsigned long max_notifications_age;
	unsigned long max_contactnotifications_age;
	unsigned long max_contactnotificationmethods_age;
	unsigned long max_logentries_age;
	unsigned long max_acknowledgements_age;
	unsigned long table_trim_interval;
} ndo2db_dbconfig;


/** DB table identifiers. */
#define NDO2DB_DBTABLE_INSTANCES                      0
#define NDO2DB_DBTABLE_CONNINFO                       1
#define NDO2DB_DBTABLE_OBJECTS                        2
#define NDO2DB_DBTABLE_OBJECTTYPES                    3
#define NDO2DB_DBTABLE_LOGENTRIES                     4
#define NDO2DB_DBTABLE_SYSTEMCOMMANDS                 5
#define NDO2DB_DBTABLE_EVENTHANDLERS                  6
#define NDO2DB_DBTABLE_SERVICECHECKS                  7
#define NDO2DB_DBTABLE_HOSTCHECKS                     8
#define NDO2DB_DBTABLE_PROGRAMSTATUS                  9
#define NDO2DB_DBTABLE_EXTERNALCOMMANDS               10
#define NDO2DB_DBTABLE_SERVICESTATUS                  11
#define NDO2DB_DBTABLE_HOSTSTATUS                     12
#define NDO2DB_DBTABLE_PROCESSEVENTS                  13
#define NDO2DB_DBTABLE_TIMEDEVENTS                    14
#define NDO2DB_DBTABLE_TIMEDEVENTQUEUE                15
#define NDO2DB_DBTABLE_FLAPPINGHISTORY                16
#define NDO2DB_DBTABLE_COMMENTHISTORY                 17
#define NDO2DB_DBTABLE_COMMENTS                       18
#define NDO2DB_DBTABLE_NOTIFICATIONS                  19
#define NDO2DB_DBTABLE_CONTACTNOTIFICATIONS           20
#define NDO2DB_DBTABLE_CONTACTNOTIFICATIONMETHODS     21
#define NDO2DB_DBTABLE_ACKNOWLEDGEMENTS               22
#define NDO2DB_DBTABLE_STATEHISTORY                   23
#define NDO2DB_DBTABLE_DOWNTIMEHISTORY                24
#define NDO2DB_DBTABLE_SCHEDULEDDOWNTIME              25
#define NDO2DB_DBTABLE_CONFIGFILES                    26
#define NDO2DB_DBTABLE_CONFIGFILEVARIABLES            27
#define NDO2DB_DBTABLE_RUNTIMEVARIABLES               28
#define NDO2DB_DBTABLE_CONTACTSTATUS                  29
#define NDO2DB_DBTABLE_CUSTOMVARIABLESTATUS           30
#define NDO2DB_DBTABLE_RESERVED31                     31
#define NDO2DB_DBTABLE_RESERVED32                     32
#define NDO2DB_DBTABLE_RESERVED33                     33
#define NDO2DB_DBTABLE_RESERVED34                     34
#define NDO2DB_DBTABLE_RESERVED35                     35
#define NDO2DB_DBTABLE_RESERVED36                     36
#define NDO2DB_DBTABLE_RESERVED37                     37
#define NDO2DB_DBTABLE_RESERVED38                     38
#define NDO2DB_DBTABLE_RESERVED39                     39

#define NDO2DB_DBTABLE_COMMANDS                       40
#define NDO2DB_DBTABLE_TIMEPERIODS                    41
#define NDO2DB_DBTABLE_TIMEPERIODTIMERANGES           42
#define NDO2DB_DBTABLE_CONTACTGROUPS                  43
#define NDO2DB_DBTABLE_CONTACTGROUPMEMBERS            44
#define NDO2DB_DBTABLE_HOSTGROUPS                     45
#define NDO2DB_DBTABLE_HOSTGROUPMEMBERS               46
#define NDO2DB_DBTABLE_SERVICEGROUPS                  47
#define NDO2DB_DBTABLE_SERVICEGROUPMEMBERS            48
#define NDO2DB_DBTABLE_HOSTESCALATIONS                49
#define NDO2DB_DBTABLE_HOSTESCALATIONCONTACTS         50
#define NDO2DB_DBTABLE_SERVICEESCALATIONS             51
#define NDO2DB_DBTABLE_SERVICEESCALATIONCONTACTS      52
#define NDO2DB_DBTABLE_HOSTDEPENDENCIES               53
#define NDO2DB_DBTABLE_SERVICEDEPENDENCIES            54
#define NDO2DB_DBTABLE_CONTACTS                       55
#define NDO2DB_DBTABLE_CONTACTADDRESSES               56
#define NDO2DB_DBTABLE_CONTACTNOTIFICATIONCOMMANDS    57
#define NDO2DB_DBTABLE_HOSTS                          58
#define NDO2DB_DBTABLE_HOSTPARENTHOSTS                59
#define NDO2DB_DBTABLE_HOSTCONTACTS                   60
#define NDO2DB_DBTABLE_SERVICES                       61
#define NDO2DB_DBTABLE_SERVICECONTACTS                62
#define NDO2DB_DBTABLE_CUSTOMVARIABLES                63
#define NDO2DB_DBTABLE_HOSTCONTACTGROUPS              64
#define NDO2DB_DBTABLE_SERVICECONTACTGROUPS           65
#define NDO2DB_DBTABLE_HOSTESCALATIONCONTACTGROUPS    66
#define NDO2DB_DBTABLE_SERVICEESCALATIONCONTACTGROUPS 67
#define NDO2DB_DBTABLE_SERVICEPARENTSERVICES          68

#define NDO2DB_NUM_DBTABLES                           69


/**************** Object types *****************/

#define NDO2DB_OBJECTTYPE_HOST                1
#define NDO2DB_OBJECTTYPE_SERVICE             2
#define NDO2DB_OBJECTTYPE_HOSTGROUP           3
#define NDO2DB_OBJECTTYPE_SERVICEGROUP        4
#define NDO2DB_OBJECTTYPE_HOSTESCALATION      5
#define NDO2DB_OBJECTTYPE_SERVICEESCALATION   6
#define NDO2DB_OBJECTTYPE_HOSTDEPENDENCY      7
#define NDO2DB_OBJECTTYPE_SERVICEDEPENDENCY   8
#define NDO2DB_OBJECTTYPE_TIMEPERIOD          9
#define NDO2DB_OBJECTTYPE_CONTACT             10
#define NDO2DB_OBJECTTYPE_CONTACTGROUP        11
#define NDO2DB_OBJECTTYPE_COMMAND             12



/** Format string for printing the SQL to use time_t as datetime.
 * (SQL query conversion of time_t format to date/time format.) */
#define NDO2DB_PRI_TIME_AS_DATE "FROM_UNIXTIME(%lu)"
/** Format string for printing the SQL to use a datetime column as timestamp.
 * (SQL query conversion of date/time format to time_t format.) */
#define NDO2DB_PRI_DATE_AS_TIME "UNIX_TIMESTAMP(%s)"

int ndo2db_db_init(ndo2db_idi *);
int ndo2db_db_deinit(ndo2db_idi *);

int ndo2db_db_connect(ndo2db_idi *);
int ndo2db_db_disconnect(ndo2db_idi *);

int ndo2db_db_hello(ndo2db_idi *);
int ndo2db_db_goodbye(ndo2db_idi *);
int ndo2db_db_checkin(ndo2db_idi *);

char *ndo2db_db_escape_string(ndo2db_idi *, char *);
char *ndo2db_db_timet_to_sql(ndo2db_idi *, time_t);

int ndo2db_db_query(ndo2db_idi *, char *);
int ndo2db_handle_db_error(ndo2db_idi *);

int ndo2db_db_clear_table(ndo2db_idi *, char *);
int ndo2db_db_get_latest_data_time(ndo2db_idi *, const char *, const char *, unsigned long *);
int ndo2db_db_perform_maintenance(ndo2db_idi *);

extern int ndo2db_log_debug_info(int, int, const char *, ...) __attribute__((format(printf, 3, 4)));

#endif
