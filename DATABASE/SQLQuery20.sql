use NCR;
select empname,emp.deptno,deptname from emp,dept where emp.deptno = dept.deptno;