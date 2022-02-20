using asp_project.Models.Entities;
using asp_project.Models.DTOs;
using asp_project.Repositories.ComponentRepository;
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
    public class ComponentController : ControllerBase
    {
        private readonly IComponentRepository _repository;
        public ComponentController(IComponentRepository repository)
        {
            _repository = repository;
        }


        [HttpPost("{option}")]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> CreateComponent(int option, CreateComponentDTO dto)
        {
            // option = 1: Add a component without a client
            // option = 2: Add a component with an existing client

            Component newComp = new Component();

            newComp.ComponentName = dto.ComponentName;
            newComp.Seller = dto.Seller;
            newComp.RecommendedForGaming = dto.RecommendedForGaming;
            newComp.Price = dto.Price;
            newComp.ClientId = dto.ClientId;

            if (option == 1)
            {
                newComp.Client = null;
                _repository.Create(newComp);
                await _repository.SaveAsync();
                return Ok(new ComponentDTO(newComp));
            }
            else
                if (option == 2)
                {
                    newComp.Client = await _repository.GetClientById(dto.ClientId);
                    _repository.Create(newComp);
                    await _repository.SaveAsync();
                    return Ok(new ComponentWithClientDTO(newComp));
                }
                else
                {
                    return BadRequest();
                }
        }


        [HttpGet("getComponentById/{id}")]
        public async Task<IActionResult> GetComponentById(int id)
        {
            var comp = await _repository.GetByIdAsync(id);
            if (comp == null)
            {
                return NotFound("The specified component does not exist!");
            }

            return Ok(new ComponentDTO(comp));
        }


        [HttpGet("getComponentByIdWithClient/{id}")]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> GetComponentByIdWithClient(int id)
        {
            var comp = await _repository.GetComponentByIdWithClient(id);
            if (comp == null)
            {
                return NotFound("The specified component does not exist!");
            }

            return Ok(new ComponentWithClientDTO(comp));
        }


        [HttpGet("getAllComponentsNotBoughtByClients")]
        public async Task<IActionResult> GetAllComponentsNotBoughtByClients()
        {
            var components = await _repository.GetAllComponentsNotBoughtByClients();

            var componentsToReturn = new List<ComponentDTO>();
            foreach (var comp in components)
            {
                componentsToReturn.Add(new ComponentDTO(comp));
            }

            return Ok(componentsToReturn);
        }


        [HttpGet("getAllComponentsBoughtByClients")]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> GetAllComponentsBoughtByClients()
        {
            var components = await _repository.GetAllComponentsBoughtByClients();

            var componentsToReturn = new List<ComponentWithClientDTO>();
            foreach (var comp in components)
            {
                componentsToReturn.Add(new ComponentWithClientDTO(comp));
            }

            return Ok(componentsToReturn);
        }


        [HttpGet("getDetailsAboutEachComponentBought")]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> GetDetailsAboutEachComponentBought()
        {
            var components = _repository.GetAll();
            var clients = await _repository.GetClients();

            var joined = clients.Join(components, cli => cli.ClientId, comp => comp.ClientId, (cli, comp) => new
            {
                comp.ComponentId,
                comp.ComponentName,
                cli.ClientId,
                ClientFullName = cli.ClientFirstName + " " + cli.ClientLastName
            });
            joined.ToList().ForEach(x =>
                Console.WriteLine($"Component with id {x.ComponentId}, named " +
                                  $"\"{x.ComponentName}\", has been bought by client with id " +
                                  $"{x.ClientId}, named {x.ClientFullName}."));

            return Ok();
        }


        [HttpPatch("{id}")]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> PatchComponent([FromRoute] int id, [FromBody] JsonPatchDocument<Component> comp)
        {
            var compToUpdate = await _repository.GetByIdAsync(id);
            if (compToUpdate == null)
            {
                return NotFound("The specified component does not exist!");
            }

            comp.ApplyTo(compToUpdate, ModelState);
            if (!ModelState.IsValid)
            {
                return BadRequest();
            }

            _repository.Update(compToUpdate);

            await _repository.SaveAsync();

            return Ok(compToUpdate);
        }


        [HttpDelete("{id}")]
        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> DeleteComponent(int id)
        {
            var comp = await _repository.GetByIdAsync(id);
            if (comp == null)
            {
                return NotFound("The specified component does not exist!");
            }

            _repository.Delete(comp);

            await _repository.SaveAsync();

            return NoContent();
        }
    }
}
