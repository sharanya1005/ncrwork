use NCR;
select empname from emp where sal in (select max(sal)from emp group by job) order by sal desc;