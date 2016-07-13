#include "gtest/gtest.h"
#include "DataBaseQueryBuilder.h"

using namespace std;

TEST(SelectClause, TEST_BASIC_SELECT)
{
	string query = DataBaseQueryBuilder().
			Select("Column").
			From("Table").
			Build();

	ASSERT_EQ("SELECT Column\nFROM Table;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_NATURAL_JOIN)
{
	string query = DataBaseQueryBuilder().
			Select("Column").
			From("Table").
			NaturalJoin("Table2").
			Build();

	ASSERT_EQ("SELECT Column\nFROM Table NATURAL JOIN Table2;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_CROSS_JOIN)
{
	string query = DataBaseQueryBuilder().
			Select("Column").
			From("Table").
			CrossJoin("Table2").
			Build();

	ASSERT_EQ("SELECT Column\nFROM Table CROSS JOIN Table2;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_NATURAL_OUTER_JOIN)
{
	string query = DataBaseQueryBuilder().
			Select("Column").
			From("Table").
			NaturalLeftOuterJoin("Table2").
			Build();

	ASSERT_EQ("SELECT Column\nFROM Table NATURAL LEFT OUTER JOIN Table2;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_ALL)
{
	string query = DataBaseQueryBuilder().
			SelectAll().
			From("Table").
			Build();

	ASSERT_EQ("SELECT *\nFROM Table;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_DISTINCT)
{
	string query = DataBaseQueryBuilder().
			Select("Column").
			Distinct().
			From("Table").
			Build();

	ASSERT_EQ("SELECT DISTINCT Column\nFROM Table;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_DISTINCT_ALL)
{
	string query = DataBaseQueryBuilder().
			SelectAll().
			Distinct().
			From("Table").
			Build();

	ASSERT_EQ("SELECT DISTINCT *\nFROM Table;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_ONE_INTEGER_CONDITION)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", 2).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column = 2;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_WHERE_IN_WITH_ONE_ELEMENT)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereIn("Column1", 1, 10).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column1 IN (10);", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_WHERE_IN_WITH_TWO_ELEMENTS)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereIn("Column1", 2, 1, 2).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column1 IN (1,2);", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_WHERE_IN_WITH_FIVE_ELEMENTS)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereIn("Column1", 5, 1, 2, 3, 4, 5).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column1 IN (1,2,3,4,5);", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_ONE_SUBQUERY)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereInQuery("Column", DataBaseQueryBuilder().Select("Column2").From("Table2").Build()).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column IN (SELECT Column2\nFROM Table2);", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_ONE_TEXT_CONDITION)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column = \'2\';", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_ONE_TEXT_LIKE_CONDITION)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereLike("Column", "_T%").
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column LIKE \'_T%\';", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_ONE_TEXT_NOT_LIKE_CONDITION)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereNotLike("Column", "_T%").
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column NOT LIKE \'_T%\';", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_MULTIPLE_CONDITIONS_AND_CLAUSE)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			And().
			WhereEqualOrLessThan("Column4", 3).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column = \'2\' AND Column4 <= 3;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_MULTIPLE_CONDITIONS_OR_CLAUSE)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			Or().
			WhereEqualOrLessThan("Column4", 3).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column = \'2\' OR Column4 <= 3;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_MULTIPLE_CONDITIONS_AND_OR_CLAUSE)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			And().
			WhereEqualOrLessThan("Column4", 3).
			Or().
			WhereEqualOrGreaterThan("Column5", 7).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column = \'2\' AND Column4 <= 3 OR Column5 >= 7;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_BETWEEN_CLAUSE)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereBetween("Column2", 3, 4).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column2 BETWEEN 3 AND 4;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_NOT_BETWEEN_CLAUSE)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereNotBetween("Column2", 3, 4).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column2 NOT BETWEEN 3 AND 4;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_GROUP_BY)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			GroupBy("Column1").
			GroupBy("Column2").
			GroupBy("Column3").
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column = \'2\'\nGROUP BY Column1, Column2, Column3;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_GROUP_BY_AND_HAVING)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			GroupBy("Column1").
			GroupBy("Column2").
			GroupBy("Column3").
			Having("Column2", 5).
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column = \'2\'\nGROUP BY Column1, Column2, Column3\nHAVING Column2 = 5;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_GROUP_BY_AND_ORDER_BY)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			GroupBy("Column1").
			GroupBy("Column2").
			GroupBy("Column3").
			OrderBy("Column1").
			OrderBy("Column2").
			OrderBy("Column3").
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column = \'2\'\nGROUP BY Column1, Column2, Column3\nORDER BY Column1, Column2, Column3;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_GROUP_BY_AND_ORDER_BY_ASC)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			GroupBy("Column1").
			GroupBy("Column2").
			GroupBy("Column3").
			OrderBy("Column1").
			OrderBy("Column2").
			OrderBy("Column3").
			Asc().
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column = \'2\'\nGROUP BY Column1, Column2, Column3\nORDER BY Column1, Column2, Column3 ASC;", query);
}

TEST(SelectClause, TEST_BASIC_SELECT_WITH_GROUP_BY_AND_ORDER_BY_DESC)
{
	string query = DataBaseQueryBuilder().
			Select("Column1").
			From("Table").
			WhereEqual("Column", "2").
			GroupBy("Column1").
			GroupBy("Column2").
			GroupBy("Column3").
			OrderBy("Column1").
			OrderBy("Column2").
			OrderBy("Column3").
			Desc().
			Build();

	ASSERT_EQ("SELECT Column1\nFROM Table\nWHERE Column = \'2\'\nGROUP BY Column1, Column2, Column3\nORDER BY Column1, Column2, Column3 DESC;", query);
}

TEST(DeleteClause, TEST_DELETE)
{
	string query = DataBaseQueryBuilder().
			Delete().
			From("Table").
			Build();

	ASSERT_EQ("DELETE FROM Table;", query);
}

TEST(DeleteClause, TEST_DELETE_WITH_CONDITION)
{
	string query = DataBaseQueryBuilder().
			Delete().
			From("Table").
			WhereEqual("Column", "2").
			Build();

	ASSERT_EQ("DELETE FROM Table\nWHERE Column = \'2\';", query);
}

TEST(DropClause, TEST_DROP_TABLE)
{
	string query = DataBaseQueryBuilder().
			Drop("Table").
			Build();

	ASSERT_EQ("DROP TABLE Table;", query);
}

TEST(DropClause, TEST_DROP_TABLE_IF_EXISTS)
{
	string query = DataBaseQueryBuilder().
			Drop("Table").
			IfExists().
			Build();

	ASSERT_EQ("DROP TABLE IF EXISTS Table;", query);
}

TEST(CreateClause, TEST_CREATE_TABLE)
{
	string query = DataBaseQueryBuilder().
			Create("Table").
			Field("Field1", "INT", true, true).
			Field("Field2", "CHAR(50)", false, true).
			Build();

	ASSERT_EQ("CREATE TABLE Table (\nField1 INT PRIMARY KEY NOT NULL,\nField2 CHAR(50) NOT NULL);", query);
}

TEST(CreateClause, TEST_CREATE_TABLE_IF_NOT_EXISTS)
{
	string query = DataBaseQueryBuilder().
			Create("Table").
			IfNotExists().
			Field("Field1", "INT", true, true).
			Field("Field2", "CHAR(50)", false, true).
			Build();

	ASSERT_EQ("CREATE TABLE IF NOT EXISTS Table (\nField1 INT PRIMARY KEY NOT NULL,\nField2 CHAR(50) NOT NULL);", query);
}

TEST(CreateClause, TEST_CREATE_TEMPORARY_TABLE_IF_NOT_EXISTS)
{
	string query = DataBaseQueryBuilder().
			Create("Table").
			Temporary().
			IfNotExists().
			Field("Field1", "INT", true, true).
			Field("Field2", "CHAR(50)", false, true).
			Build();

	ASSERT_EQ("CREATE TEMPORARY TABLE IF NOT EXISTS Table (\nField1 INT PRIMARY KEY NOT NULL,\nField2 CHAR(50) NOT NULL);", query);
}

TEST(UpdateClause, TEST_UPDATE_TABLE)
{
	string query = DataBaseQueryBuilder().
			Update("Table").
			Set("Column1", "2").
			Set("Column2", 3).
			Build();

	ASSERT_EQ("UPDATE Table\nSET Column1 = \'2\', Column2 = 3;", query);
}

TEST(UpdateClause, TEST_UPDATE_TABLE_WITH_CONDITION)
{
	string query = DataBaseQueryBuilder().
			Update("Table").
			Set("Column1", "2").
			Set("Column2", 3).
			WhereLessThan("Column3", 4).
			Build();

	ASSERT_EQ("UPDATE Table\nSET Column1 = \'2\', Column2 = 3\nWHERE Column3 < 4;", query);
}

TEST(InsertClause, TEST_INSERT_INTO_TABLE)
{
	string query = DataBaseQueryBuilder().
			InsertInto("Table").
			Values("SomeText").
			Values("2").
			Values(3).
			Build();

	ASSERT_EQ("INSERT INTO Table\nVALUES (\'SomeText\', \'2\', 3);", query);
}

TEST(AlterClause, TEST_ALTER_RENAME)
{
	string query = DataBaseQueryBuilder().
			Alter("Table").
			RenameTo("Table1").
			Build();

	ASSERT_EQ("ALTER Table RENAME TO Table1;", query);
}

TEST(AlterClause, TEST_ALTER_ADD_COLUMN)
{
	string query = DataBaseQueryBuilder().
			Alter("Table").
			AddColumn("Field1", "INT", true, true).
			Build();

	ASSERT_EQ("ALTER Table ADD COLUMN Field1 INT PRIMARY KEY NOT NULL;", query);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
