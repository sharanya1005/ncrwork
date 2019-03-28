use NCR;
select deptno, min(sal)"minimum salary in dept" from emp group by deptno having min(sal)>1000;