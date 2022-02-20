using asp_project.Models.Entities;
using asp_project.Models.DTOs;
using asp_project.Repositories.EmployeeRepository;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.JsonPatch;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Authorization;

namespace asp_project.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class EmployeeController : ControllerBase
    {
        private readonly IEmployeeRepository _repository;
        public EmployeeController(IEmployeeRepository repository)
        {
            _repository = repository;
        }


        [HttpPost]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> CreateEmployee(CreateEmployeeDTO dto)
        {
            Employee newEmp = new Employee();

            newEmp.Role = dto.Role;
            newEmp.EmployeeLastName = dto.EmployeeLastName;
            newEmp.EmployeeFirstName = dto.EmployeeFirstName;
            newEmp.Salary = dto.Salary;
            newEmp.PhoneNumber = dto.PhoneNumber;

            _repository.Create(newEmp);

            await _repository.SaveAsync();

            return Ok(new EmployeeDTO(newEmp));
        }


        [HttpGet("{id}")]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> GetEmployeeById(int id)
        {
            var emp = await _repository.GetByIdAsync(id);
            if (emp == null)
            {
                return NotFound("The specified employee does not exist!");
            }

            return Ok(new EmployeeDTO(emp));
        }


        [HttpGet("getAllEmployees")]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> GetAllEmployees()
        {
            var employees = await _repository.GetAllEmployees();

            var employeesToReturn = new List<EmployeeDTO>();
            foreach (var emp in employees)
            {
                employeesToReturn.Add(new EmployeeDTO(emp));
            }

            return Ok(employeesToReturn);
        }


        [HttpPatch("{id}")]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> PatchEmployee([FromRoute] int id, [FromBody] JsonPatchDocument<Employee> emp)
        {
            var empToUpdate = await _repository.GetByIdAsync(id);
            if (empToUpdate == null)
            {
                return NotFound("The specified employee does not exist!");
            }

            emp.ApplyTo(empToUpdate, ModelState);
            if (!ModelState.IsValid)
            {
                return BadRequest();
            }

            _repository.Update(empToUpdate);

            await _repository.SaveAsync();

            return Ok(empToUpdate);
        }


        [HttpDelete("{id}")]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> DeleteEmployee(int id)
        {
            var emp = await _repository.GetByIdAsync(id);
            if (emp == null)
            {
                return NotFound("The specified employee does not exist!");
            }

            _repository.Delete(emp);

            await _repository.SaveAsync();

            return NoContent();
        }
    }
}
