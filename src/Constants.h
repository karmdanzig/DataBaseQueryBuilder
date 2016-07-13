#include <string>

#ifndef SRC_CONSTANTS_H_
#define SRC_CONSTANTS_H_

using namespace std;

typedef enum
{
	None = 0,
	SelectQuery,
	DeleteQuery,
	InsertQuery,
	UpdateQuery,
	CreateQuery,
	DropQuery,
	AlterQuery,
} QueryType;

const string TerminationQueryCharacter = ";";
const string Table = "TABLE";
const string SelectClause = "SELECT";
const string DeleteClause = "DELETE";
const string InsertIntoClause = "INSERT INTO";
const string UpdateClause = "UPDATE";
const string DropClause = "DROP";
const string CreateClause = "CREATE";
const string AlterClause = "ALTER";
const string FromClause = "FROM";
const string JoinClause = "JOIN";
const string NaturalClause = "NATURAL";
const string OuterClause = "OUTER";
const string LeftClause = "LEFT";
const string CrossClause = "CROSS";
const string WhereClause = "WHERE";
const string AndClause = "AND";
const string OrClause = "OR";
const string SetClause = "SET";
const string ValuesClause = "VALUES";
const string PrimaryKeyClause = "PRIMARY KEY";
const string NotNullClause = "NOT NULL";
const string LikeClause = "LIKE";
const string EqualClause = "=";
const string GreaterClause = ">";
const string LessClause = "<";
const string GreaterOrEqualClause = ">=";
const string LessOrEqualClause = "<=";
const string GroupByClause = "GROUP BY";
const string HavingClause = "HAVING";
const string OrderByClause = "ORDER BY";
const string AscClause = "ASC";
const string DescClause = "DESC";
const string DistinctClause = "DISTINCT";
const string InClause = "IN";
const string AsClause = "AS";
const string NotClause = "NOT";
const string BetweenClause = "BETWEEN";
const string IfExistsClause = "IF EXISTS";
const string IfNotExistsClause = "IF NOT EXISTS";
const string TemporaryClause = "TEMPORARY";
const string RenameToClause = "RENAME TO";
const string AddColumnClause = "ADD COLUMN";

#endif /* SRC_CONSTANTS_H_ */
