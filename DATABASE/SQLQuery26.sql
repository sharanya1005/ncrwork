use NCR;
select deptname from dept where deptno not in (select deptno from emp);