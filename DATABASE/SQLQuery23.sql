use NCR;
select empname, deptno from emp where deptno = (select deptno from dept where location = 'dallas');