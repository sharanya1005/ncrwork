use NCR;
select empname, sal + isnull(comm, 0) "Remuneration" from emp;
 