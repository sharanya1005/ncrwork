use NCR;
select empname, location, deptname from emp,dept where emp.deptno = dept.deptno and sal>1500;