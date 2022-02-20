using asp_project.Repositories;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace asp_project.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class UserController : ControllerBase
    {
        private readonly IRepositoryWrapper _repository;

        public UserController(IRepositoryWrapper repository)
        {
            _repository = repository;
        }


        [HttpGet("getUserById/{id}")]
        [Authorize]
        public async Task<IActionResult> GetUserByIdWithRoles(int id)
        {
            var user = await _repository.User.GetUserByIdWithRoles(id);
            if (user == null)
            {
                return NotFound("The user with the specified id does not exist!");
            }

            return Ok(new { user });
        }


        [HttpGet("getUserByEmail/{email}")]
        [Authorize]
        public async Task<IActionResult> GetUserByEmail(string email)
        {
            var user = await _repository.User.GetUserByEmail(email);
            if (user == null)
            {
                return NotFound("The user with the specified e-mail does not exist!");
            }

            return Ok(new { user });
        }


        [HttpGet("getAllUsers")]
        [Authorize]
        public async Task<IActionResult> GetAllUsers()
        {
            var users = await _repository.User.GetAllUsers();

            return Ok(new { users });
        }
    }
}